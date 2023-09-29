#include "systemc.h"
using std::cout;
using std::endl;

SC_MODULE(Adder){
    sc_in<sc_logic> A, B, Cin;
    sc_out<sc_logic> Sum, Cout;

    SC_CTOR(Adder){
        SC_METHOD(add_method);
        sensitive << A << B << Cin;
    }

    void add_method(void);
};