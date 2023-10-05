#include "systemc.h"
using std::cout;
using std::endl;

SC_MODULE(Battery){

    float CLOCK_PERIOD_MS = 1;

    sc_in<float> battery_cap;
    sc_in<float> current;

    sc_out<float> voc;
    
    // Signals ending in '_1' hold the value from the previous clock cycle
    // They are used for integration
    sc_signal<bool> battery_clock;
    sc_signal<float> c_rate, c_rate_1;
    sc_signal<float> soc, soc_1;    

    SC_CTOR(Battery){
        SC_THREAD(sim_battery_clock);

        SC_METHOD(c_rate_method);
        sensitive << current << battery_cap;

        SC_THREAD(soc_integrator_thread);
        sensitive << battery_clock.posedge_event();

        SC_METHOD(soc_to_voc_method);
        sensitive << soc;
    }

    void sim_battery_clock(void);
    void c_rate_method(void);
    void soc_integrator_thread(void);
    void soc_to_voc_method(void);

};