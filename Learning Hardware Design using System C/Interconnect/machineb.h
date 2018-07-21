#include "systemc.h"
#include "common.h"
#include "time.h"

SC_MODULE(MachineB)
{
    sc_in< sc_bv<8> >  inpB;
    sc_out< sc_bv<8> > outpB;

    sc_inout_resolved CLK;

	void run()
	{
		sc_bv<8> byte;

		while (true) {
			wait(CLK.posedge_event());
			
			byte = rand()%256;
            outpB.write(byte);
			
			for (int i = 0; i < 4; ++i)
			{
				CLK.write(SC_LOGIC_0); wait(1,SC_NS);
				CLK.write(SC_LOGIC_1); wait(1,SC_NS);
			}
		}
	}

	SC_CTOR(MachineB)
	{
		SC_THREAD(run);
		srand(time(NULL));
	}
};
