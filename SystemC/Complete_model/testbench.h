#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "systemc.h"
using std::cout;
using std::endl;

SC_MODULE(Testbench){
    sc_in<float> voc;

    sc_out<float> battery_cap;      // Battery capacity [Ah]
    sc_out<float> current;          // Current [A]

    SC_CTOR(Testbench){
        SC_THREAD(generator_thread);
        SC_THREAD(checker_thread);
        //SC_METHOD(checker_method);
        //sensitive << voc;
    }

    void checker_method(void);
    void checker_thread(void);
    void generator_thread(void);
};