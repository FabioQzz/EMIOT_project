#include "systemc.h"
#include "adder.h"
#include "testbench.h"

int sc_main(int argc, char * argv[]) {

    sc_signal<sc_logic> A_sig("A"), B_sig("B"), Cin_sig("Cin"), Cout_sig("Cout"), Sum_sig("Sum");

    Adder Adder_inst("Adder_Obj");
    Testbench TB_inst("Testbench_Obj");

    Adder_inst.A(A_sig);
    Adder_inst.B(B_sig);
    Adder_inst.Cin(Cin_sig);
    Adder_inst.Cout(Cout_sig);
    Adder_inst.Sum(Sum_sig);

    TB_inst.A(A_sig);
    TB_inst.B(B_sig);
    TB_inst.Cin(Cin_sig);
    TB_inst.Cout(Cout_sig);
    TB_inst.Sum(Sum_sig);

    sc_start();

	return 0;
}