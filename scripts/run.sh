#!/bin/bash

cd /home/pi/Projects/vehicle

./bin/vehicle &

sleep 0.1

python ./python/detect.py &

