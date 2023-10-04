#include "testbench.h"

void Testbench::checker_method(void){
    cout << "Checking result at time " << sc_time_stamp() << endl;
    cout << "Voc: " << voc << endl;
}

void Testbench::generator_thread(void){
    // Launch dynamic SC_THREAD for clock simulation
    sc_spawn( sc_bind(&Testbench::simulation_clock, this, 1));
    
    current = 0;
    battery_cap = 1000;
    wait(5, SC_MS);
    current = 1;
    wait(100, SC_MS);
}

void Testbench::simulation_clock(float clock_period_MS){
    while(true){
        sim_clock.write(true);
        wait(clock_period_MS/2,SC_MS); 
        sim_clock.write(false);
        wait(clock_period_MS/2,SC_MS);
    }
}

