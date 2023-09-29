#include "testbench.h"

void Testbench::generator_thread(void){
    A = SC_LOGIC_0; B = SC_LOGIC_0; Cin = SC_LOGIC_0;
    evt_checker.notify(SC_ZERO_TIME);
    wait(5, SC_NS);
    A = SC_LOGIC_0; B = SC_LOGIC_0; Cin = SC_LOGIC_1;
    evt_checker.notify(SC_ZERO_TIME);
    wait(5, SC_NS);
    A = SC_LOGIC_0; B = SC_LOGIC_1; Cin = SC_LOGIC_0;
    evt_checker.notify(SC_ZERO_TIME);
    wait(5, SC_NS);
    A = SC_LOGIC_0; B = SC_LOGIC_1; Cin = SC_LOGIC_1;
    evt_checker.notify(SC_ZERO_TIME);
    wait(5, SC_NS);
    A = SC_LOGIC_1; B = SC_LOGIC_0; Cin = SC_LOGIC_0;
    evt_checker.notify(SC_ZERO_TIME);
    wait(5, SC_NS);
    A = SC_LOGIC_1; B = SC_LOGIC_0; Cin = SC_LOGIC_1;
    evt_checker.notify(SC_ZERO_TIME);
    wait(5, SC_NS);
    A = SC_LOGIC_1; B = SC_LOGIC_1; Cin = SC_LOGIC_0;
    evt_checker.notify(SC_ZERO_TIME);
    wait(5, SC_NS);
    A = SC_LOGIC_1; B = SC_LOGIC_1; Cin = SC_LOGIC_1;
    evt_checker.notify(SC_ZERO_TIME);
    wait(5, SC_NS);
    
}

void Testbench::checker_method(void){
    cout << "Checking result at time " << sc_time_stamp() << endl;
    cout << "A: " << A->read() << endl;
    cout << "B: " << B->read() << endl;
    cout << "Cin: " << Cin->read() << endl;
    cout << "Sum: " << Sum->read() << endl;
    cout << "Cout: " << Cout->read() << endl;
    cout << endl;
}