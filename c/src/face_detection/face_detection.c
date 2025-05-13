/*
 * @Author       : moon-dim zsjmoon@qq.com
 * @Date         : 2025-05-13 14:33:53
 * @LastEditTime : 2025-05-13 14:58:26
 * @FilePath     : \vehicle\c\src\face_detection\face_detection.cpp
 * @Description  : 
 */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <Python.h>
#include "data.h"

void face_init(void)
{
    __init__();
    Py_Initialize();
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_FromString("./python"));
}

void face_final(void)
{
    Py_Finalize();
}

void face_score(void) //python下face_detect函数返回的是已经经过提取和取证过的置信度score，是个int型
{
    PyObject *pModule = PyImport_ImportModule("detect"); //加载python文件
    if (!pModule)
    {
        PyErr_Print();
        printf("Error: failed to load module\n");
        goto FAILED_MODULE; //goto的意思就是如果运行到这里就直接跳转到FAILED_MODULE
    }
    PyObject *pFunc = PyObject_GetAttrString(pModule, "run"); //加载python文件中的对应函数
    if (!pFunc)
    {
        PyErr_Print();
        printf("Error: failed to load function\n");
        goto FAILED_FUNC;
    }
    PyObject *pArgs = Py_BuildValue("sddiii","python/models/detector.tflite", 0.8, 0.5, 0, 640, 480);

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

int main()
{
	int score = 0;
	face_init();
	face_score();
    while(1){
        ;
    }
	face_final();
	return 0;
}