#include <stdio.h>
#include <Python.h>
#define _USE_MATH_DEFINES
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <math.h>
#include "arrayobject.h"
#include "myext.h"


/* #### Globals #################################### */

/* ==== Set up the methods table ====================== */
static PyMethodDef func_methods[] = {
	{"mycfunc", MyCFunc, METH_VARARGS, "Python interface for the GibbsSampling C library function"},
	{NULL, NULL, 0, NULL}     /* Sentinel - marks the end of this structure */
};

/* ==== Initialize the C_test functions ====================== */
// Module name must be _C_arraytest in compile and linked 
static struct PyModuleDef mod_definition =
{
    PyModuleDef_HEAD_INIT,
    "myext",
    "Python interface for the GibbsSampling C library function",
    -1,
    func_methods
};


PyMODINIT_FUNC PyInit_myext(void) {
    Py_Initialize();
    _import_array();
    return PyModule_Create(&mod_definition);
}


static PyObject* MyCFunc(PyObject *self, PyObject *args) {

    PyArrayObject *py_vec, *output;
    if (!PyArg_ParseTuple(args, "O!", &PyArray_Type, &py_vec)) return NULL;

    npy_float64* vec = (npy_float64*)PyArray_DATA(py_vec);
    npy_intp* N = PyArray_DIMS(py_vec);
    double mean = 0;
    int i;

    for(i = 0; i < N[0]; ++i) {
       mean += vec[i];
       vec[i] += 1.;
    }

    mean /= (double)N[0];
//	return Py_BuildValue("d", mean);
	output = (PyArrayObject *) PyArray_SimpleNewFromData(1, N, NPY_DOUBLE, vec);
    return Py_BuildValue("O", output);
}
