#include <python2.7/Python.h>

#define MODULE "_validator"

struct bit {
    int bit;  
};

static void
bit_destructor(PyObject *py_bit)
{
    struct bit *b;

    b = (struct bit *) PyCapsule_GetPointer(py_bit, NULL);
    free(b);
}

static void
and_gate(struct bit *out, const struct bit *a, const struct bit *b)
{
    out->bit = a->bit & b->bit;
}

static void
xor_gate(struct bit *out, const struct bit *a, const struct bit *b)
{
    out->bit = a->bit ^ b->bit;
}

static PyObject *
ext_input_wire(PyObject *self, PyObject *args)
{
    int input;
    struct bit *out;

    if (!PyArg_ParseTuple(args, "i", &input))
        return NULL;

    if (input != 0 && input != 1)
        return NULL;

    out = (struct bit *) malloc(sizeof(struct bit));
    if (out == NULL)
        return NULL;

    out->bit = input;

    return PyCapsule_New((void *) out, NULL, bit_destructor);
}

static PyObject *
ext_output_wire(PyObject *self, PyObject *args)
{
    PyObject *py_inp;
    struct bit *inp;

    if (!PyArg_ParseTuple(args, "O", &py_inp))
        return NULL;

    inp = (struct bit *) PyCapsule_GetPointer(py_inp, NULL);
    if (inp == NULL)
        return NULL;

    return PyInt_FromLong(inp->bit);
}


static PyObject *
ext_and_gate(PyObject *self, PyObject *args)
{
    PyObject *py_a, *py_b;
    struct bit *a, *b, *out;

    if (!PyArg_ParseTuple(args, "OO", &py_a, &py_b))
        return NULL;

    a = (struct bit *) PyCapsule_GetPointer(py_a, NULL);
    if (a == NULL)
        return NULL;
    b = (struct bit *) PyCapsule_GetPointer(py_b, NULL);
    if (b == NULL)
        return NULL;

    out = (struct bit *) malloc(sizeof(struct bit));
    if (out == NULL)
        return NULL;

    and_gate(out, a, b);

    return PyCapsule_New((void *) out, NULL, bit_destructor);
}

static PyObject *
ext_xor_gate(PyObject *self, PyObject *args)
{
    PyObject *py_a, *py_b;
    struct bit *a, *b, *out;

    if (!PyArg_ParseTuple(args, "OO", &py_a, &py_b))
        return NULL;

    a = (struct bit *) PyCapsule_GetPointer(py_a, NULL);
    if (a == NULL)
        return NULL;
    b = (struct bit *) PyCapsule_GetPointer(py_b, NULL);
    if (b == NULL)
        return NULL;

    out = (struct bit *) malloc(sizeof(struct bit));
    if (out == NULL)
        return NULL;

    xor_gate(out, a, b);

    return PyCapsule_New((void *) out, NULL, bit_destructor);
}

static PyMethodDef
ExtMethods[] = {
    {"input_wire", ext_input_wire, METH_VARARGS, "Input."},
    {"output_wire", ext_output_wire, METH_VARARGS, "Output."},
    {"and_gate", ext_and_gate, METH_VARARGS, "AND gate."},
    {"xor_gate", ext_xor_gate, METH_VARARGS, "XOR gate."},
    {NULL, NULL, 0, NULL},
};

PyMODINIT_FUNC
init_validator(void)
{
    (void) Py_InitModule(MODULE, ExtMethods);
}

