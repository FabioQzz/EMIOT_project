#include "systemc.h"
#include "testbench.h"
#include "battery.h"

int sc_main(int argc, char * argv[]) {

    sc_signal<float>    battery_cap_s("Battery_capacity");
    sc_signal<float>    current_s("Current");
    sc_signal<float>    voc_s("Voltage");

    Battery Battery_inst("Battery_obj");
    Testbench TB_inst("Testbench_obj");

    Battery_inst.battery_cap(battery_cap_s);
    Battery_inst.current(current_s);
    Battery_inst.voc(voc_s);

    TB_inst.battery_cap(battery_cap_s);
    TB_inst.current(current_s);
    TB_inst.voc(voc_s);

    sc_start(3600, SC_SEC);

	return 0;
}