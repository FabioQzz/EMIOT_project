#include "battery.h"

void Battery::c_rate_method(void){
    
    // TODO: CCF not yet implemented
    c_rate = current / ((battery_cap / 3600) * 1);
}

void Battery::soc_integrator_thread(void){
    // Values initialization
    soc = 0;
    soc_1 = 0;
    c_rate_1 = 0;
    //c_rate = 0;
    wait(SC_ZERO_TIME);
    wait(SC_ZERO_TIME);

    while(true){
        // Right trapezoid formula, linear approximation
        soc = soc_1 + ((c_rate + c_rate_1) * (float)sim_clock_period_S / 2);
        c_rate_1 = c_rate;
        soc_1 = soc;
        //cout << "C_rate " << c_rate << "   C_rate_1 " << c_rate_1 << "    time " << sc_time_stamp() << endl;
        //cout << "SoC " << soc << " time " << sc_time_stamp() << endl;
        //cout << "SoC -1 " << soc_1 << " time " << sc_time_stamp() << endl;
        //cout << "C-rate " << c_rate << " time " << sc_time_stamp() << endl;
        //cout << "C-rate -1 " << c_rate_1 << " time " << sc_time_stamp() << endl;
        //cout << endl;
        wait();
    }
}

void Battery::soc_to_voc_method(void){
    // TODO: implement
    voc = soc;
}