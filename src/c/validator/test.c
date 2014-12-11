#include "validator.c"

int main(){
   struct bit* a = input_wire(1);
   struct bit* b = input_wire(1);
   struct bit* c = input_wire(0);
   and_gate(c, a, b);
   printf("%d", output_wire(c));
return 0;
}
