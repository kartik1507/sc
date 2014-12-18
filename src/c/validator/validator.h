#ifndef VALIDATOR_H__
#define VALIDATOR_H__
#include "includes.h"
typedef bool bit[1];

void init();
void assign(bit, bit);
bit* new_bit_array(int length);
void delete_bit_array(bit** bits, int length);

void and(bit out, const bit a, const bit b);
void xor(bit out, const bit a, const bit b);

void input_wire(bit out, bool input, enum Party party);
void input_wire_array(bit* out, bool* input, int length, enum Party party);
void output_wire(bool* res, bit b, enum Party party);
void output_wire_array(bool* out, bit* b, int length, enum Party party);

bit ONE;
bit ZERO;
#endif //VALIDATOR_H__
