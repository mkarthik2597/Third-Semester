#include "systemc.h"
#include "machinea.h"
#include "machineb.h"

int sc_main(int argc, char *argv[])
{
	sc_signal< sc_bv<8> > AB;
	sc_signal< sc_bv<8> > BA;
	sc_signal_resolved CLK;
	
	MachineA A("A");
	MachineB B("B");

	A.inpA(BA);
	A.outpA(AB);
	A.CLK(CLK);

	B.inpB(AB);
	B.outpB(BA);
	B.CLK(CLK);

	sc_set_time_resolution(1, SC_NS);
	sc_start(100, SC_NS);
}
