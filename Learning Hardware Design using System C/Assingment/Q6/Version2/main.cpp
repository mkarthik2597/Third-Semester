/*
 * CS701 - High Performance Computing
 * +--- Programming Assignments
 *      +--- A1 - SystemC and OpenMP
 *           +--- SystemC Programming
 *                +--- Basic Interconnection Network
 *
 * Testrunner implementation
 */


#include "systemc.h"
#include "machinea.h"
#include "machineb.h"

int sc_main(int argc, char *argv[])
{
	sc_signal< sc_bv<8> > TX_A;
	sc_signal< sc_bv<8> > TX_B;
	sc_signal_resolved CLK;
	
	MachineA NA("MachineA");
	MachineB NB("MachineB");

	NA.RX(TX_B);
	NA.TX(TX_A);
	NA.CLK(CLK);

	NB.RX(TX_A);
	NB.TX(TX_B);
	NB.CLK(CLK);

	sc_set_time_resolution(1, SC_SEC);
	sc_start(500, SC_SEC);

	return EXIT_SUCCESS;
}
