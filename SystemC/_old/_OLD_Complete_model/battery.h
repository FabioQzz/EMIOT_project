#include "systemc.h"
using std::cout;
using std::endl;

SC_MODULE(Battery){

    const float CLOCK_PERIOD_MS = 1;        // Simulation clock period in milliseconds
    const float CHECK_PERIOD_MS = 1;        // Output checking period in milliseconds

    // Input variables
    float clock_period      = CLOCK_PERIOD_MS / 1000;
    float current           = 0;
    float init_cap          = 0;
    float storage_time      = 1;
    float temperature       = 25;
    float init_cycle_n      = 1;
    float init_soc          = 0;

    // Output variables
    float v_batt            = 0;
    float ccf               = 0;
    float soc               = 0;

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