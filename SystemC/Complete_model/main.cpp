#include "systemc.h"
#include "battery.h"

int sc_main(int argc, char * argv[]) {

    Battery Battery_inst("Battery_obj");

    sc_start(30, SC_MS);

	return 0;
}