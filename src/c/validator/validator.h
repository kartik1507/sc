#ifndef VALIDATOR_H__
#define VALIDATOR_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
typedef int bit;

static void 
new_bit(bit** b) {
   *b = malloc(sizeof(bit));
}     

static void new_bit_array(bit*** bits, int length) {
   int i;
   *bits = malloc(length*sizeof(bit*));
   for(i = 0; i < length; ++i)
      new_bit(&(*bits)[i]);
}
static void 
new_bits(int number, ...) {
   int i;
   bit** b;
   va_list args;
   va_start (args, number);
   for(i = 0; i < number; ++i){
      b = va_arg(args, bit**);
      new_bit(b);
   }
}

static void 
delete_bit(bit** b) {
   free(*b);
   b = NULL;
}

static void
delete_bit_array(bit*** bits, int length) {
   int i;
   for(i = 0; i < length; ++i)
      delete_bit(&(*bits)[i]);
   free(*bits);
   *bits = NULL;
}

static void 
delete_bits(int number, ...)
{
   int i;
   va_list args;
   va_start (args, number);
   for(i = 0; i < number; ++i)
      delete_bit(va_arg(args, bit**));
}

static void 
and(bit* out, const bit* a, const bit* b)
{
   *out = (*a) & (*b);
}

static void 
xor(bit* out, const bit* a, const bit* b)
{
   *out = (*a) ^ (*b);
}

static void 
input_wire(bit* out, int input)
{
   *out = input;
}

static int 
output_wire(bit* b)
{
   return *b;
}
#endif //VALIDATOR_H__
