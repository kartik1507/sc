#include "config.h"
#include "circuits/int_circuits.h"

int main(){
   bit* a, *b;
   new_bits(2, &a, &b);
   input_wire(a, 1);
   input_wire(b, 0);
   bit** c;
   new_bit_array(&c, 2);
   add(c, a,  b, b);
   printf("%d\n", output_wire(c[0]));
   printf("%d\n", output_wire(c[1]));
   delete_bit_array(&c, 2);
   return 0;
}
