#include "testbench.h"

void Testbench::checker_method(void){
    cout << "Time " << sc_time_stamp() << "  Voc: " << voc << endl;
}

void Testbench::checker_thread(void){
    while(true){
        cout << "Time " << sc_time_stamp() << "  Voc: " << voc << endl;
        wait(100,SC_MS);
    }
}

void Testbench::generator_thread(void){
    current = 0;
    battery_cap = 1;
    wait(5, SC_MS);
    current = 1;
    wait(100, SC_MS);
}


