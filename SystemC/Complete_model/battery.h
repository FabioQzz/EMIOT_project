#include "systemc.h"
using std::cout;
using std::endl;

SC_MODULE(Battery){

    const float CLOCK_PERIOD_MS = 1;        // Simulation clock period in milliseconds
    const float CHECK_PERIOD_MS = 10;       // Output checking period in milliseconds

    float current = 0;
    float battery_cap = 1;

    sc_signal<bool> battery_clock;
  

    SC_CTOR(Battery){
        SC_THREAD(sim_battery_clock);

        SC_THREAD(sim_battery_model);
        sensitive << battery_clock.posedge_event();

        SC_THREAD(input_generation);

        SC_THREAD(checker_thread);
    }

    void checker_thread(void);
    void input_generation(void);
    void sim_battery_clock(void);
    void sim_battery_model(void);

};