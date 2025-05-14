/*
 * @Author       : moon-dim zsjmoon@qq.com
 * @Date         : 2025-05-13 14:33:53
 * @LastEditTime : 2025-05-13 14:58:26
 * @FilePath     : \vehicle\c\src\face_detection\face_detection.cpp
 * @Description  : 
 */


#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <pthread.h>
#include "public_data.h"
#include "cmd_fac.h"
#include "device_fac.h"
#include "mqtt_conf.h"

void py_init()
{
    public_data_init();
    Py_Initialize();
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_FromString("/home/pi/Projects/vehicle/python"));
}

void py_final()
{
    Py_Finalize();
}

void *py_start()
{
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();

    //加载python文件
    PyObject *pModule = PyImport_ImportModule("detect"); 

    //加载python文件中的对应函数
    PyObject *pFunc = PyObject_GetAttrString(pModule, "run");

    PyObject *pArgs = Py_BuildValue("sddiii","/home/pi/Projects/vehicle/python/models/detector.tflite", 0.85, 0.5, 0, 640, 480);

    PyObject_CallObject(pFunc, pArgs);

    PyGILState_Release(gstate);

    pthread_exit(NULL);
}
