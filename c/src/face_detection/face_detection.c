/*
 * @Author       : moon-dim zsjmoon@qq.com
 * @Date         : 2025-05-13 14:33:53
 * @LastEditTime : 2025-05-13 14:58:26
 * @FilePath     : \vehicle\c\src\face_detection\face_detection.cpp
 * @Description  : 
 */


#include "public_data.h"
#include "face_detection.h"

void py_init()
{
    Py_Initialize();
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_FromString("../../../python"));
}

void py_final()
{
    Py_Finalize();
}

void py_start()
{
    //加载python文件
    PyObject *pModule = PyImport_ImportModule("detect"); 
    if (!pModule)
    {
        PyErr_Print();
        printf("Error: failed to load module\n");
        goto FAILED_MODULE; 
    }

    //加载python文件中的对应函数
    PyObject *pFunc = PyObject_GetAttrString(pModule, "run");
    if (!pFunc)
    {
        PyErr_Print();
        printf("Error: failed to load function\n");
        goto FAILED_FUNC;
    }
    PyObject *pArgs = Py_BuildValue("sddiii","python/models/detector.tflite", 0.85, 0.5, 0, 640, 480);

    PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
    if (!pValue)
    {
        PyErr_Print();
        printf("Error: function call failed\n");
        goto FAILED_VALUE;
    }
 
FAILED_RESULT:
    Py_DECREF(pValue);
FAILED_VALUE:
    Py_DECREF(pFunc);
FAILED_FUNC:
    Py_DECREF(pModule);
FAILED_MODULE:
    return;
}
