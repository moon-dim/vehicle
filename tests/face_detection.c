/*
 * @Author       : moon-dim zsjmoon@qq.com
 * @Date         : 2025-05-13 14:33:53
 * @LastEditTime : 2025-05-13 14:58:26
 * @FilePath     : \vehicle\c\src\face_detection\face_detection.cpp
 * @Description  : 
 */


#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "public_data.h"
#include "cmd_fac.h"
#include "device_fac.h"
#include "mqtt_conf.h"

void py_init()
{
    Py_Initialize();
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_FromString("."));
}

void py_final()
{
    Py_Finalize();
}

void py_start()
{
    PyObject *pModule = PyImport_ImportModule("detect"); //����python�ļ�
    if (!pModule)
    {
        PyErr_Print();
        printf("Error: failed to load module\n");
        goto FAILED_MODULE; //goto����˼����������е������ֱ����ת��FAILED_MODULE
    }
    PyObject *pFunc = PyObject_GetAttrString(pModule, "run"); //����python�ļ��еĶ�Ӧ����
    if (!pFunc)
    {
        PyErr_Print();
        printf("Error: failed to load function\n");
        goto FAILED_FUNC;
    }
    PyObject *pArgs = Py_BuildValue("sddiii","models/detector.tflite", 0.85, 0.5, 0, 640, 480);

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

int main(){
    py_init();

	//��������߳�
	py_start();
	
	py_final();
}
