# Copyright 2023 The MediaPipe Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
"""Main scripts to run face detector."""

import argparse
import sys
import os
import time
import threading
import mmap
import posix_ipc
import ctypes

import cv2
import subprocess
import mediapipe as mp

from mediapipe.tasks import python
from mediapipe.tasks.python import vision

from utils import visualize

lib_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '/home/pi/Projects/vehicle/libs'))
print(lib_path)
sys.path.insert(0, lib_path)
import libc_utils as c_utils


class Attribute(ctypes.Structure):
  _fields_ = [
      ("beeper", ctypes.c_int),
      ("humidity", ctypes.c_int),
      ("temperature", ctypes.c_float),
      ("pressure", ctypes.c_float),
      ("gas", ctypes.c_float),
      ("face_detection", ctypes.c_int),
      ("led_green", ctypes.c_bool),
      ("led_yellow", ctypes.c_bool),
      ("led_red", ctypes.c_bool),
      ("in_car", ctypes.c_bool),
      ("fire_ctl", ctypes.c_bool),
      ("window", ctypes.c_bool),
      ("hand_ctl", ctypes.c_bool)
  ]

shm = None
sem = None
attribute_ptr = None

# Global variables to calculate FPS
COUNTER, FPS = 0, 0
START_TIME = time.time()
DETECTION_RESULT = None


def run(model: str, min_detection_confidence: float,
        min_suppression_threshold: float, camera_id: int, width: int,
        height: int) -> None:
  """Continuously run inference on images acquired from the camera.

  Args:
    model: Name of the TFLite face detection model.
    min_detection_confidence: The minimum confidence score for the face
      detection to be considered successful.
    min_suppression_threshold: The minimum non-maximum-suppression threshold for
      face detection to be considered overlapped.
    camera_id: The camera id to be passed to OpenCV.
    width: The width of the frame captured from the camera.
    height: The height of the frame captured from the camera.
  """

  global shm, sem, attribute_ptr
  
  # c_utils.init_c()

  # Start capturing video input from the camera
  cap = cv2.VideoCapture(camera_id, cv2.CAP_V4L2)
  cap.set(cv2.CAP_PROP_FRAME_WIDTH, width)
  cap.set(cv2.CAP_PROP_FRAME_HEIGHT, height)
  cap.set(cv2.CAP_PROP_FPS, 20)

  ffmpeg_cmd = [
    'ffmpeg',
    '-y',
    '-f', 'rawvideo',
    '-pix_fmt', 'bgr24',
    '-s', '640x480',
    '-r', '20',
    '-i', '-',
    '-c:v', 'libx264',
    '-f', 'flv',
    '-preset', 'ultrafast',
    '-tune', 'zerolatency',
    'rtmp://47.93.33.13/live/stream'
  ]

  proc = subprocess.Popen(ffmpeg_cmd, stdin=subprocess.PIPE)

  # Visualization parameters
  row_size = 50  # pixels
  left_margin = 24  # pixels
  text_color = (0, 0, 0)  # black
  font_size = 1
  font_thickness = 1
  fps_avg_frame_count = 10

  def save_result(result: vision.FaceDetectorResult, unused_output_image: mp.Image,
                  timestamp_ms: int):
      global FPS, COUNTER, START_TIME, DETECTION_RESULT

      # Calculate the FPS
      if COUNTER % fps_avg_frame_count == 0:
          FPS = fps_avg_frame_count / (time.time() - START_TIME)
          START_TIME = time.time()

      DETECTION_RESULT = result.detections
      COUNTER += 1

  # Initialize the face detection model
  base_options = python.BaseOptions(model_asset_path=model)
  options = vision.FaceDetectorOptions(base_options=base_options,
                                       running_mode=vision.RunningMode.LIVE_STREAM,
                                       min_detection_confidence=min_detection_confidence,
                                       min_suppression_threshold=min_suppression_threshold,
                                       result_callback=save_result)
  detector = vision.FaceDetector.create_from_options(options)

  tmp_value = 0
  # Continuously capture images from the camera and run inference
  while cap.isOpened():
    success, image = cap.read()
    if not success:
      sys.exit(
          'ERROR: Unable to read from webcam. Please verify your webcam settings.'
      )

    image = cv2.flip(image, 1)

    # Convert the image from BGR to RGB as required by the TFLite model.
    rgb_image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb_image)

    # Run face detection using the model.
    detector.detect_async(mp_image, time.time_ns() // 1_000_000)

    # Show the FPS
    fps_text = 'FPS = {:.1f}'.format(FPS)
    text_location = (left_margin, row_size)
    current_frame = image
    cv2.putText(current_frame, fps_text, text_location, cv2.FONT_HERSHEY_DUPLEX,
                font_size, text_color, font_thickness, cv2.LINE_AA)

    if DETECTION_RESULT:
      # print(DETECTION_RESULT)
      current_frame = visualize(current_frame, DETECTION_RESULT)
      if tmp_value==0:
        tmp_value = 1
        # c_utils.send_to_c(1)

        sem.acquire()
        attribute_ptr.face_detection = 1
        sem.release()

    elif tmp_value==1:
      tmp_value = 0
      # c_utils.send_to_c(0)

      sem.acquire()
      attribute_ptr.face_detection = 0
      sem.release()

    # print(c_utils.get_from_c())

    proc.stdin.write(current_frame.tobytes())
    # cv2.imshow("face",current_frame)
    
    # Stop the program if the ESC key is pressed.
    if cv2.waitKey(1) == 27:
      break

  detector.close()
  cap.release()
  proc.stdin.close()

def thread_create(model: str, min_detection_confidence: float,
        min_suppression_threshold: float, camera_id: int, width: int,
        height: int):
  t = threading.Thread(target=run,
                      args=(model,min_detection_confidence,min_suppression_threshold,camera_id,width,height))
  t.start()
  t.join()

def init():
  global shm, sem, attribute_ptr

  SHM_NAME = "/attr_shm"
  SEM_NAME = "/attr_sem"
  shm_size = ctypes.sizeof(Attribute)

  shm = posix_ipc.SharedMemory(SHM_NAME)
  sem = posix_ipc.Semaphore(SEM_NAME)
  
  mem = mmap.mmap(shm.fd, shm_size, access=mmap.ACCESS_WRITE)
  shm.close_fd()
  
  attribute_ptr = Attribute.from_buffer(mem)

if __name__ == "__main__":
  init()
  run("/home/pi/Projects/vehicle/python/models/detector.tflite", 0.85, 0.5, 0, 640, 480)