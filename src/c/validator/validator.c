#include "validator/validator.h"

void 
new_bit(bit** b) {
   *b = malloc(sizeof(bit));
}     

void new_bit_array(bit*** bits, int length) {
   int i;
   *bits = malloc(length*sizeof(bit*));
   for(i = 0; i < length; ++i)
      new_bit(&(*bits)[i]);
}
void 
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

void 
delete_bit(bit** b) {
   free(*b);
   b = NULL;
}

void
delete_bit_array(bit*** bits, int length) {
   int i;
   for(i = 0; i < length; ++i)
      delete_bit(&(*bits)[i]);
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


void input_wire(bit** out, int* input, int length, int party)
{
   int i;
   new_bit_array(&out, length);
   for(i = 0; i < length; ++i)
      input_wire(&out[i], input[i], party);
}

output_wire(int * out, bit** b, int length, int party)
{
}
