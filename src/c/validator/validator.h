#ifndef VALIDATOR_H__
#define VALIDATOR_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
typedef int bit;

void new_bit(bit** b);
void new_bit_array(bit*** bits, int length);
void new_bits(int number, ...);

void delete_bit(bit** b);
void delete_bit_array(bit*** bits, int length);
void delete_bits(int number, ...);

void and(bit* out, const bit* a, const bit* b);
void xor(bit* out, const bit* a, const bit* b);

void input_wire(bit* out, int input);
int output_wire(bit* b);
#endif //VALIDATOR_H__
