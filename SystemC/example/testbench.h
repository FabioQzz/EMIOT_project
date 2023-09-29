#include "systemc.h"
using std::cout;
using std::endl;

SC_MODULE(Testbench){
    sc_in<sc_logic> Sum, Cout;
    sc_out<sc_logic> A, B, Cin;

    sc_event evt_checker;

    SC_CTOR(Testbench){
        SC_THREAD(generator_thread);
        SC_METHOD(checker_method);
        //sensitive << evt_checker;
        sensitive << Sum << Cout;
    }

    void generator_thread(void);
    void checker_method(void);
};