#include "battery.h"

void Battery::sim_battery_clock(void){
    while(true){
        battery_clock.write(true);
        wait(CLOCK_PERIOD_MS/2,SC_MS); 
        battery_clock.write(false);
        wait(CLOCK_PERIOD_MS/2,SC_MS);
    }
}

void Battery::c_rate_method(void){
    
    // TODO: CCF not yet implemented
    c_rate = current / ((battery_cap * 3600) * 1);
}

void Battery::soc_integrator_thread(void){
    // Values initialization
    soc = 0;
    c_rate_1 = 0;
    //c_rate = 0;
    wait(SC_ZERO_TIME);
    wait(SC_ZERO_TIME);

    while(true){
        // Right trapezoid formula, linear approximation
        soc = soc + ((c_rate + c_rate_1) * CLOCK_PERIOD_MS/1000 / 2);
        c_rate_1 = c_rate;

        //cout << "Time " << sc_time_stamp() << endl;
        //cout << "C-rate: now " << c_rate << "  prev " << c_rate_1 << endl;
        //cout << "SoC:    now " << soc << "  prev " << soc_1 << endl;
        //cout << "Delta Soc:  " << ((c_rate + c_rate_1) * CLOCK_PERIOD_MS/1000 / 2) <<endl;
        //cout << endl;
        wait();
    }
}

void Battery::soc_to_voc_method(void){
    // TODO: implement
    voc = soc;
}