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
#include "cmd_fac.h"
#include "device_fac.h"
#include "mqtt_conf.h"

struct mosquitto     *mosquit_ptr       = NULL;
mosquitto_inf        *mosquit_inf_ptr   = NULL;
attribute            *attribute_ptr     = NULL;
cmd	                 *cmd_phead         = NULL;
device	             *device_phead      = NULL;

void public_data_init(){
    mosquit_inf_ptr    = (mosquitto_inf*)malloc(sizeof(mosquitto_inf));
    attribute_ptr      = (attribute*)malloc(sizeof(attribute));
    cmd_phead          = (cmd*)malloc(sizeof(cmd));
    device_phead       = (device*)malloc(sizeof(device));
}

// Python�ӿں���
static PyObject* init_c(PyObject* self) {
    public_data_init();
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


// ģ�鷽����
static PyMethodDef C_utilsMethods[] = {
    {"init_c", (PyCFunction)init_c, METH_NOARGS, "Set data of C global"},
    {"send_to_c", (PyCFunction)send_to_c, METH_VARARGS, "Send data to C global"},
    {"get_from_c", (PyCFunction)get_from_c, METH_NOARGS, "Get data from C global"},
    {NULL, NULL, 0, NULL}
};

// ģ�鶨��
static struct PyModuleDef c_utilsmodule  = {
    PyModuleDef_HEAD_INIT,
    "c_utils",
    NULL,
    -1,
    C_utilsMethods
};

// ģ���ʼ������
PyMODINIT_FUNC PyInit_c_utils(void) {
    return PyModule_Create(&c_utilsmodule);
}