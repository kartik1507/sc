#include "config.h"
#include "includes.h"
#include "circuits/int_circuits.h"

int main(){
   bit a, b;
   input_wire(&a, 1, Alice);
   input_wire(&b, 0, Bob);
   bit* c = new_bit_array(2);
   add(c, &a,  &b, &b);
   printf("%d\n", output_wire(&a, Alice));
   printf("%d\n", output_wire(&b, Alice));
   delete_bit_array(&c, 2);
   return 0;
}
