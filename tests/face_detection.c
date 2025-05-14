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
#include <sys/select.h>


PyObject *pModule, *pFunc, *pArgs;
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

void *py_start()
{
    printf("5\n");
    //Py_BEGIN_ALLOW_THREADS
    printf("6\n");
    
    PyObject_CallObject(pFunc, pArgs);
    printf("7\n");

    //Py_END_ALLOW_THREADS

    py_final();
    pthread_exit(NULL);
}

void *tmp(){
    while(1){
        printf("11111111\n\n");
       sleep(2);
    }
}

void *tmp2(){
    while(1){
        printf("22222222\n");
        sleep(3);
    }
}

int main(){
    py_init();
    pthread_t tid1;
    //pthread_t tid2;
	pthread_t tid3;
    //py_start();


    printf("1\n");
    pModule = PyImport_ImportModule("detect"); //加载python文件

    printf("2\n");

    pFunc = PyObject_GetAttrString(pModule, "thread_create"); //加载python文件中的对应函数

    printf("3\n");

    pArgs = Py_BuildValue("sddiii","models/detector.tflite", 0.85, 0.5, 0, 640, 480);
    printf("4\n");


    pthread_create(&tid3, NULL, py_start, NULL);
    printf("Thread worker3 tid[%lu] created ok\n", tid3);

	pthread_create(&tid1, NULL, tmp, NULL);
    printf("Thread worker3 tid[%lu] created ok\n", tid1);

    // pthread_create(&tid2, NULL, tmp2, NULL);
    // printf("Thread worker3 tid[%lu] created ok\n", tid2);

	
	pthread_join(tid3,NULL);
    pthread_join(tid1,NULL);
    // pthread_join(tid2,NULL);
	
	
	//py_final();
}
