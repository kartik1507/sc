#include "config.h"
#include "includes.h"
#include "circuits/int_circuits.h"

void testcase(bool in1, bool in2){
   bit a, b, c;
   bool rc;
   input_wire(a, in1, Alice);
   input_wire(b, in2, Bob);
   xor(c, a, b);
   output_wire(&rc, c, Alice);
   printf("%d %d %d\n", in1, in2, rc);
   assert(rc == (in1 ^ in2));
}

int main()
{
   testcase(true, false);
   testcase(false, true);
   testcase(true, true);
   testcase(false, false);
}
