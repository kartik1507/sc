#include "validator/validator.h"

void assign(bit a, bit b)
{
   *a = *b;
}

bit* new_bit_array(int length)
{
   return malloc(length*sizeof(bit));
}

void
delete_bit_array(bit** bits, int length) {
   free(*bits);
   *bits = NULL;
}

void 
and(bit out, const bit a, const bit b)
{
   *out = (*a) & (*b);
}

void 
xor(bit out, const bit a, const bit b)
{
   *out = (*a) ^ (*b);
}

void 
input_wire(bit out, bool input, enum Party party)
{
   *out = input;
}

void 
input_wire_array(bit* out, bool* input, int length, enum Party party)
{
   int i;
   for(i = 0; i < length; ++i)
      input_wire(out[i], input[i], party);
}

bool
output_wire(bit b, enum Party party)
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
