#include "config.h"
#include "circuits/int_circuits.c"
int main(){
   bit a = input_wire(1);
   bit b = input_wire(0);
   bit* c = add(a,  b, b);
   printf("%d\n", output_wire(c[0]));
   printf("%d\n", output_wire(c[1]));
   return 0;
}
