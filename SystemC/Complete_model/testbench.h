#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "systemc.h"
using std::cout;
using std::endl;

SC_MODULE(Testbench){
    sc_in<float> voc;

    sc_out<float> battery_cap;
    sc_out<float> current;
    sc_out<bool> sim_clock;
    

    SC_CTOR(Testbench){
        SC_THREAD(generator_thread);
        SC_METHOD(checker_method);
        sensitive << voc;
    }

    void generator_thread(void);
    void checker_method(void);
    void simulation_clock(float clock_period_MS);
};