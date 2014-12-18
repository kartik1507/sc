#include "config.h"
#include "includes.h"
#include "circuits/int_circuits.h"

int main() {
   bit a[32], b[32], c[32];
   bool ra[32], rb[32], rc[32];
   int_to_bools(ra, 10, 32);
   int_to_bools(rb, 10, 32);
   input_wire_array(a, ra, 32, Alice); 
   input_wire_array(b, rb, 32, Alice); 
   clock_t start = clock();
   for(int i = 0; i < 1000000; ++i)   
      add(c, a, b, 32);
   clock_t end = clock();
   float seconds = (float)(end - start) / CLOCKS_PER_SEC;
   printf("%f", seconds);
   output_wire_array(rc, c, 32, Alice);
   printf("%d\n", bools_to_int(rc, 32));
   return 0;
}
