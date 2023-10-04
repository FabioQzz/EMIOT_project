#define SC_INCLUDE_FX
#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "systemc.h"
using std::cout;
using std::endl;

SC_MODULE(Testbench){
    sc_in<sc_fixed<32, 16, SC_RND, SC_SAT>> soc;
    sc_out<sc_fixed<32, 16, SC_RND, SC_SAT>> current;
    sc_out<sc_logic> sim_clock;
    

    //sc_time clk_period (1, SC_MS);
    //sc_clock clk("clk", sc_time(1,SC_MS), 0.5);

    SC_CTOR(Testbench){
        SC_THREAD(generator_thread);
        SC_METHOD(checker_method);
        sensitive << soc;
    }

    void generator_thread(void);
    void checker_method(void);
    void simulation_clock(int clock_period_MS);
};