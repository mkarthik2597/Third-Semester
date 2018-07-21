#include"systemc.h"
#include"time.h"
SC_MODULE(machineB)
{
	sc_in< sc_bv<8> > inpB;
	sc_out< sc_bv<8> > outpB;
    
	sc_inout_resolved CLK;

	
	void run()
	{
		sc_bv<8> byte;
		while(true)
		{
			wait(CLK.posedge_event());
            
			byte=rand()%256;
			outpB.write(byte);
			
			CLK.write(SC_LOGIC_0);
			wait(1,SC_NS);
			CLK.write(SC_LOGIC_1);
			wait(1,SC_NS);
		}
		
		sc_stop();
	}
	
	SC_CTOR(machineB)
	{
		srand(time(NULL));
		SC_THREAD(run);
	}
};