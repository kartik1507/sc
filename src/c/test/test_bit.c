#include "config.h"
#include "includes.h"
#include "circuits/int_circuits.h"

int test(bool in1, bool in2){
   bit a, b;
   input_wire(a, in1, Alice);
   input_wire(b, in2, Bob);
   bit* c = new_bit_array(2);
   full_bit_adder(c, a,  b, b);
   bool ra, rb;
   output_wire(&ra, a, Alice);
   output_wire(&rb, b, Alice);
   assert()
   printf("%d", ra);
   printf("%d\n", rb);
   delete_bit_array(&c, 2);
   return 0;
}
