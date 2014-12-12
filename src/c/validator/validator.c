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
input_wire(bit* out, bool input, enum Party party)
{
   *out = input;
}

void 
input_wire_array(bit* out, bool* input, int length, enum Party party)
{
   int i;
   for(i = 0; i < length; ++i)
      input_wire(&out[i], input[i], party);
}

bool
output_wire(bit* b, enum Party party)
{
   return *b;
}

void 
output_wire_array(bool* out, bit* b, int length, enum Party party)
{
   int i;
   for(i = 0; i < length; ++i)
      out[i] = b[i];
}
