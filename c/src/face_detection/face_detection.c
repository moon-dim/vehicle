/*
 * @Author       : moon-dim zsjmoon@qq.com
 * @Date         : 2025-05-13 14:33:53
 * @LastEditTime : 2025-05-13 14:58:26
 * @FilePath     : \vehicle\c\src\face_detection\face_detection.cpp
 * @Description  : 
 */


#define PY_SSIZE_T_CLEAN
#include "face_detection.h"

PyObject *pModule = NULL;
PyObject *pFunc   = NULL;
PyObject *pArgs   = NULL;

void py_init()
{
    Py_Initialize();
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_FromString("/home/pi/Projects/vehicle/python"));
    PyList_Append(path, PyUnicode_FromString("/home/pi/Projects/vehicle/libs"));

    //加载python文件
    pModule = PyImport_ImportModule("detect");

    //加载python文件中的对应函数
    pFunc = PyObject_GetAttrString(pModule, "thread_create");

    pArgs = Py_BuildValue("sddiii","/home/pi/Projects/vehicle/python/models/detector.tflite", 0.85, 0.5, 0, 640, 480);

}

void py_final()
{
    Py_Finalize();
}

void *py_start()
{
    PyObject_CallObject(pFunc, pArgs);
    pthread_exit(NULL);
}
