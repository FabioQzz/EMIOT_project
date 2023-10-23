#include "battery.h"
#include "src/battery_model.h"

void Battery::checker_thread(void){
    while(true){
        cout << "Time " << sc_time_stamp() << "  current: " << current << endl;
        wait(CHECK_PERIOD_MS/2,SC_MS);
    }
}

void Battery::input_generation(void){
    current     = 0;
    init_cap    = 1;
    wait(5, SC_MS);
    current     = 1;
    wait(100, SC_MS);
}

void Battery::sim_battery_clock(void){
    while(true){
        battery_clock.write(true);
        wait(CLOCK_PERIOD_MS/2,SC_MS); 
        battery_clock.write(false);
        wait(CLOCK_PERIOD_MS/2,SC_MS);
    }
}

void Battery::sim_battery_model(void){
    while(true){
        //cout << "Current var: " << current << endl;
        battery_model(  current,
                        init_cap,
                        storage_time,
                        temperature,
                        init_cycle_n,
                        init_soc,
                        &v_batt,
                        &ccf,
                        &soc);
        wait();
    }
}


