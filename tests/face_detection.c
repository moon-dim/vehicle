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
#include <unistd.h>
#include "public_data.h"

PyObject *pModule, *pFunc, *pArgs;
void py_init()
{
    Py_Initialize();
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_FromString("."));
    PyList_Append(path, PyUnicode_FromString("./libs"));
    printf("1\n");
    pModule = PyImport_ImportModule("detect"); //加载python文件
    if(!pModule){
        printf("no find pmodule!");
    }

    printf("2\n");

    pFunc = PyObject_GetAttrString(pModule, "thread_create"); //加载python文件中的对应函数

    printf("3\n");

    pArgs = Py_BuildValue("sddiii","models/detector.tflite", 0.85, 0.5, 0, 640, 480);
}

void py_final()
{
    Py_Finalize();
}

void *py_start()
{
    
    printf("4\n");

    PyObject_CallObject(pFunc, pArgs);
    printf("5\n");

    py_final();
}

void *tmp(){
    while(1){
        printf("attribute_ptr address of address cccccc:%d\n\n",&attribute_ptr);
        if(attribute_ptr != NULL)printf("attribute_ptr init finish!!! address:%d\n\n",attribute_ptr);
        else printf("attribute_ptr init fail!!!\n\n");
       sleep(2);
    }
}


int main(){

    printf("attribute_ptr address of address ccccccccccc1:%d\n\n",&attribute_ptr);

    py_init();
    pthread_t tid1;
    pthread_t tid2;

	pthread_create(&tid1, NULL, tmp, NULL);
    printf("Thread worker3 tid[%lu] created ok\n", tid1);

    pthread_create(&tid2, NULL, py_start, NULL);
    printf("Thread worker3 tid[%lu] created ok\n", tid2);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
}
