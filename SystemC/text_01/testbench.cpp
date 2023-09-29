#include "testbench.h"

void Testbench::generator_thread(void){
    current = 0;
    wait(5, SC_MS);
    current = 1;
    wait(100, SC_SEC);
}

void Testbench::checker_method(void){
    cout << "Checking result at time " << sc_time_stamp() << endl;
    cout << "SoC: " << soc << endl;
}