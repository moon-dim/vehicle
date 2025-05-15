/*
 * @Author       : moon-dim zsjmoon@qq.com
 * @Date         : 2025-05-13 14:33:41
 * @LastEditTime : 2025-05-13 14:50:42
 * @FilePath     : \vehicle\c\src\py_c_utils\c_utilsmoudle.c
 * @Description  : 
 */
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "public_data.h"

attribute *attribute_ptr = NULL;

// Python接口函数
static PyObject* init_c(PyObject* self) {
    attribute_ptr = (attribute*)malloc(sizeof(attribute));
    printf("attribute_ptr init finish! address:%d\n\n\n",attribute_ptr);
    Py_RETURN_NONE;
}

static PyObject* send_to_c(PyObject* self, PyObject* args) {
    int value = false;
    PyArg_ParseTuple(args, "i", &value);
    if(attribute_ptr){
        attribute_ptr->face_detection = value;
    }
    Py_RETURN_NONE;
}

static PyObject* get_from_c(PyObject* self) {
    if(attribute_ptr) {
        return Py_BuildValue("i", attribute_ptr->face_detection);
    }
    printf("nothing!\n");
    Py_RETURN_NONE;
}


// 模块方法表
static PyMethodDef C_utilsMethods[] = {
    {"init_c", (PyCFunction)init_c, METH_NOARGS, "Set data of C global"},
    {"send_to_c", (PyCFunction)send_to_c, METH_VARARGS, "Send data to C global"},
    {"get_from_c", (PyCFunction)get_from_c, METH_NOARGS, "Get data from C global"},
    {NULL, NULL, 0, NULL}
};

// 模块定义
static struct PyModuleDef c_utilsmodule  = {
    PyModuleDef_HEAD_INIT,
    "c_utils",
    NULL,
    -1,
    C_utilsMethods
};

// 模块初始化函数
PyMODINIT_FUNC PyInit_libc_utils(void) {
    return PyModule_Create(&c_utilsmodule);
}