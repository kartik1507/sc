#include "validator/validator.h"

bit* 
new_bit()
{
   return malloc(sizeof(bit));
}     

bit* new_bit_array(int length)
{
   return malloc(length*sizeof(bit));
}

void 
new_bits(int number, ...) {
   int i;
   bit** b;
   va_list args;
   va_start (args, number);
   for(i = 0; i < number; ++i) {
      b = va_arg(args, bit**);
      *b = new_bit();
   }
}

void 
delete_bit(bit** b) {
   free(*b);
   *b = NULL;
}

void
delete_bit_array(bit** bits, int length) {
   free(*bits);
   *bits = NULL;
}

void 
delete_bits(int number, ...)
{
   int i;
   va_list args;
   va_start (args, number);
   for(i = 0; i < number; ++i)
      delete_bit(va_arg(args, bit**));
}

void 
and(bit* out, const bit* a, const bit* b)
{
   *out = (*a) & (*b);
}

void 
xor(bit* out, const bit* a, const bit* b)
{
   *out = (*a) ^ (*b);
}

void 
input_wire(bit* out, int input, int party)
{
   *out = input;
}

int 
output_wire(bit* b, int party)
{
   return *b;
}
