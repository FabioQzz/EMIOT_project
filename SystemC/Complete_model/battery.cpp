#include "battery.h"

void Battery::c_rate_method(void){
    
    // TODO: CCF not yet implemented
    c_rate = current / ((battery_cap / 3600) * 1);
    //c_rate = current / ((battery_cap / 3600) * CCF);
}

void Battery::soc_integrator_thread(void){
    while(true){
        // Right trapezoid formula, linear approximation
        soc = (c_rate + c_rate_1) * sim_clock_period_S / 2;
        c_rate_1 = c_rate;
        wait();
    }
}

void Battery::soc_to_voc_method(void){
    // TODO: implement
    voc = soc;
}