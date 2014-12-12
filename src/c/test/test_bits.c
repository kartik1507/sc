#include "config.h"
#include "includes.h"
#include "circuits/int_circuits.h"

int main() {
   bit a[32];
   bit b[32];
   bool b1[32], b2[32];
   int_to_bools(b1, 10, 32);
   int_to_bools(b2, 10, 32);
   input_wire_array(a, b1, 32, Alice); 
   input_wire_array(a, b2, 32, Alice); 
   bit c[32];
   add(c, a, b, 32);
   bool res[32];
   output_wire_array(res, b1, 32, Alice);
   printf("%d\n", bools_to_int(res, 32));
   return 0;
}
