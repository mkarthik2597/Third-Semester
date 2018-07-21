#include"systemc.h"
#include"machinA.h"
#include"machinB.h"

int sc_main(int argc, char*argv[])
{
	sc_signal< sc_bv<8> >sigAB;
	sc_signal< sc_bv<8> >sigBA;
	sc_signal_resolved CLK;
	
	machineA A("A");
	machineB B("B");
	
	A.inpA(sigBA);
	A.outpA(sigAB);
	A.CLK(CLK);
	
	B.inpB(sigAB);
	B.outpB(sigBA);
	B.CLK(CLK);
	
	sc_set_time_resolution(1, SC_NS);
	sc_start(50, SC_NS);
}