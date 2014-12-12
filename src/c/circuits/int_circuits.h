#ifndef INT_CIRCUITS_H__
#define INT_CIRCUITS_H__
#include "config.h"
#define VALIDATE
void 
full_bit_adder(bit out[2], const bit* x, const bit* y, const bit* cin);

void 
add(bit* out, const bit* x, const bit * y, int length);
#endif // INT_CIRCUITS_H__
