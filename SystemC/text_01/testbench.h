#include "systemc.h"
using std::cout;
using std::endl;

SC_MODULE(Testbench){
    sc_out<sc_fixed<32, 16, SC_RND, SC_SAT> > current;
    sc_in<sc_fixed<32, 16, SC_RND, SC_SAT> > soc;

    sc_time clk_period (1, SC_MS);
    sc_clock clk("clk", clk_period, 0.5);

    SC_CTOR(Testbench){
        SC_THREAD(generator_thread);
        SC_METHOD(checker_method);
        sensitive << 
    }

    void generator_thread(void);
}