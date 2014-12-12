#include "config.h"
#include "circuits/int_circuits.c"
int main(){
   bit* a, *b;
   new_bits(2, &a, &b);
   input_wire(a, 1);
   input_wire(b, 0);
   bit** c = malloc(2*sizeof(bit*));
   new_bit(&c[0]);
   new_bit(&c[1]);
   add(c, a,  b, b);
   printf("%d\n", output_wire(c[0]));
   printf("%d\n", output_wire(c[1]));
   return 0;
}
