#include "adder.h"

void Adder::add_method(void) {
    Sum->write(A^B^Cin);
    Cout->write((A & B) ^ (Cin & (A^B)));
}