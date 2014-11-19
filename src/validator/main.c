#include <python2.7/Python.h>
#include <stdio.h>

#define MODULE "_validator"
#define LENGTH 32

typedef struct {
    int bit;  
} bit;

static void
bit_destructor(PyObject *py_bit)
{
  /*bit *b;

    b = (bit *) PyCapsule_GetPointer(py_bit, NULL);
    free(b);*/
}

static void
and_gate(bit *out, const bit *a, const bit *b)
{
    out->bit = a->bit & b->bit;
}

static void
xor_gate(bit *out, const bit *a, const bit *b)
{
    out->bit = a->bit ^ b->bit;
}

static PyObject *
ext_input_wire(PyObject *self, PyObject *args)
{
    int input;
    bit *out;

    if (!PyArg_ParseTuple(args, "i", &input))
        return NULL;

    if (input != 0 && input != 1)
        return NULL;

    out = (bit *) malloc(sizeof(bit));
    if (out == NULL)
        return NULL;

    out->bit = input;

    return PyCapsule_New((void *) out, NULL, bit_destructor);
}

static PyObject *
ext_output_wire(PyObject *self, PyObject *args)
{
    PyObject *py_inp;
    bit *inp;

    if (!PyArg_ParseTuple(args, "O", &py_inp))
        return NULL;

    inp = (bit *) PyCapsule_GetPointer(py_inp, NULL);
    if (inp == NULL)
        return NULL;

    return PyInt_FromLong(inp->bit);
}


static PyObject *
ext_and_gate(PyObject *self, PyObject *args)
{
    PyObject *py_a, *py_b;
    bit *a, *b, *out;

    if (!PyArg_ParseTuple(args, "OO", &py_a, &py_b))
        return NULL;

    a = (bit *) PyCapsule_GetPointer(py_a, NULL);
    if (a == NULL)
        return NULL;
    b = (bit *) PyCapsule_GetPointer(py_b, NULL);
    if (b == NULL)
        return NULL;

    out = (bit *) malloc(sizeof(bit));
    if (out == NULL)
        return NULL;

    and_gate(out, a, b);

    return PyCapsule_New((void *) out, NULL, bit_destructor);
}

static PyObject *
ext_xor_gate(PyObject *self, PyObject *args)
{
    PyObject *py_a, *py_b;
    bit *a, *b, *out;

    if (!PyArg_ParseTuple(args, "OO", &py_a, &py_b))
        return NULL;

    a = (bit *) PyCapsule_GetPointer(py_a, NULL);
    if (a == NULL)
        return NULL;
    b = (bit *) PyCapsule_GetPointer(py_b, NULL);
    if (b == NULL)
        return NULL;

    out = (bit *) malloc(sizeof(bit));
    if (out == NULL)
        return NULL;

    xor_gate(out, a, b);

    return PyCapsule_New((void *) out, NULL, bit_destructor);
}

bit** getBinary(int a) {
  int i;
  bit** num = (bit **) malloc(LENGTH * sizeof(bit *));
  for (i = 0; i < LENGTH; i++) {
    num[i] = (bit *) malloc(sizeof(bit)); 
    if (num[i] == NULL)
        return NULL;
    num[i]->bit = a % 2;
    a = a / 2;
  }
  return num;
}

bit** add(bit* x, bit* y, bit* cin) {
  bit *t1, *t2;
  bit **ret = (bit **) malloc(2 * sizeof(bit *));
  xor_gate(t1, x, cin);
  xor_gate(t2, y, cin);
  xor_gate(t1, x, cin);
  xor_gate(t2, y, cin);
  xor_gate(ret[0], x, t2);
  and_gate(t1, t1, t2);
  xor_gate(ret[1], cin, t1);
  return ret;
}

// bit[] addFull()

static PyObject *
ext_add(PyObject * self, PyObject *args) {
  int a = 0, b = 0;
  if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;
  //fprintf(stderr, "%d%d\n", a, b);
  bit** num1 = getBinary(a);
  bit** num2 = getBinary(b);
  bit** ret = add(num1[0], num2[0], num2[0]);
  fprintf(stderr, "%d%d\n", ret[1]->bit, ret[0]->bit);
  return NULL;//PyCapsule_New((void *) ret[0], NULL, bit_destructor);;
}

static PyMethodDef
ExtMethods[] = {
    {"input_wire", ext_input_wire, METH_VARARGS, "Input."},
    {"output_wire", ext_output_wire, METH_VARARGS, "Output."},
    {"and_gate", ext_and_gate, METH_VARARGS, "AND gate."},
    {"xor_gate", ext_xor_gate, METH_VARARGS, "XOR gate."},
    {"add", ext_add, METH_VARARGS, "ADD two numbers."},
    {NULL, NULL, 0, NULL},
};

PyMODINIT_FUNC
init_validator(void)
{
    (void) Py_InitModule(MODULE, ExtMethods);
}

