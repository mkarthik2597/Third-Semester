/*
 * CS701 - High Performance Computing
 * +--- Programming Assignments
 *      +--- A1 - SystemC and OpenMP
 *           +--- SystemC Programming
 *                +--- Basic Interconnection Network
 *
 * Machine A implementation
 */

#include "time.h"
#include "systemc.h"
#include "common.h"

SC_MODULE(MachineA)
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
			byte = rand() % 256;

			TX.write(byte);
			cout << "TX: " << byte << endl;

			CLK.write(SC_LOGIC_0); wait(CLOCK_DELAY);
			CLK.write(SC_LOGIC_1); wait(CLOCK_DELAY);

			for (int i = 0; i < RX_REPLIES; ++i) 
			{
				wait(CLK.posedge_event());

				byte = RX.read();
				cout << "RX: " << byte << endl;
			}

			wait((rand() % 20) + 20, SC_SEC);
		}
	}

	SC_CTOR(MachineA)
	{
		srand(time(NULL));
		SC_THREAD(run);
	}
};
