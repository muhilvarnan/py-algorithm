#include <Python.h>
#include <numpy/arrayobject.h>
#include "../headers/segment_tree.h"

static char module_docstring[] = "This is a module for segment tree";
static char segment_tree_docstring[] = "segment tree";
static PyObject *segment_tree_segment_tree(PyObject *self, PyObject *args);

static PyMethodDef module_methods[] = {
    {"segment_tree", segment_tree_segment_tree, METH_VARARGS, segment_tree_docstring},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC init_segment_tree(void)
{
    PyObject *m = Py_InitModule3("_segment_tree", module_methods, module_docstring);
    if (m == NULL)
        return;

    /* Load `numpy` functionality. */
    import_array();
}


static PyObject *segment_tree_segment_tree(PyObject *self, PyObject *args)
{
    double m;
    PyObject *x_obj, *y_obj, *yerr_obj;

    /* Parse the input tuple */
    if (!PyArg_ParseTuple(args, "d", &m))
        return NULL;

    /* Interpret the input objects as numpy arrays. */
     /* Call the external C function to compute the chi-squared. */
    double value = segment_tree(m);

    if (value < 0.0) {
        PyErr_SetString(PyExc_RuntimeError,
                    "No data");
        return NULL;
    }

    /* Build the output tuple */
    PyObject *ret = Py_BuildValue("d", value);
    return ret;
}