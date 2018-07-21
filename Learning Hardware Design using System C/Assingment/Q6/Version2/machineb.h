/*
 * CS701 - High Performance Computing
 * +--- Programming Assignments
 *      +--- A1 - SystemC and OpenMP
 *           +--- SystemC Programming
 *                +--- Basic Interconnection Network
 *
 * Machine B implementation
 */


#include "systemc.h"
#include "common.h"

SC_MODULE(MachineB)
{
	/* Input */
	sc_in< sc_bv<8> >  RX;

	/* Output */
	sc_out< sc_bv<8> > TX;

	/* Common */
	sc_inout_resolved CLK;

	void run()
	{
		sc_bv<8> byte;

		while (true) {
			wait(CLK.posedge_event());
			
			byte = RX.read();
            TX.write(byte);
			
			for (int i = 0; i < RX_REPLIES; ++i) {
				
				CLK.write(SC_LOGIC_0); wait(CLOCK_DELAY);
				CLK.write(SC_LOGIC_1); wait(CLOCK_DELAY);
			}
		}
	}

	SC_CTOR(MachineB)
	{
		SC_THREAD(run);
	}
};
