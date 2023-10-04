#include "systemc.h"
using std::cout;
using std::endl;

SC_MODULE(Battery){
    sc_in<float> battery_cap;
    sc_in<float> current;
    sc_in<bool> sim_clock;

    sc_out<float> voc;
    
    // Signals ending in '_1' hold the value from the previous clock cycle
    // They are used for integration
    sc_signal<float> c_rate, c_rate_1;
    sc_signal<float> soc;

    double sim_clock_period_S;
    

    SC_CTOR(Battery){
        SC_METHOD(c_rate_method);
        sensitive << current << battery_cap;

        SC_THREAD(soc_integrator_thread);
        sensitive << sim_clock.pos();

        SC_METHOD(soc_to_voc_method);
        sensitive << current << battery_cap;

    }

    void c_rate_method(void);
    void soc_integrator_thread(void);
    void soc_to_voc_method(void);

    // Function to extract clock period from signal sim_clock
    void start_of_simulation() {
        sc_clock *channel = dynamic_cast<sc_clock *>(sim_clock.get_interface());
        sim_clock_period_S = channel->period().to_seconds();
    };

};