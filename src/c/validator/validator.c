#ifndef VALIDATOR_H_
#define VALIDATOR_H_
#include <stdio.h>
#include <stdlib.h>

typedef int bit;

static bit bit_constructor(){
   return 0;
}
static void
bit_destructor(bit b)
{}

static bit
and(const bit a, const bit b)
{
   return a & b;
}

static bit
xor(const bit a, const bit b)
{
   return a ^ b;
}

static bit
input_wire(int input)
{
   return input;
}

static int
output_wire(bit b)
{
   return b;
}

#endif
