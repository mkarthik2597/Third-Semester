#include"systemc.h"
#include"time.h"
SC_MODULE(machineA)
{
	sc_in< sc_bv<8> > inpA;
	sc_out< sc_bv<8> > outpA;
	sc_inout_resolved CLK;
	
	void run()
	{
		sc_bv<8> byte;
		
		while(true)
		{
            byte=rand()%256;
			outpA.write(byte);
			cout<<"   "<<byte<<" Sent from A to B  "<<sc_time_stamp()<<endl;
			
			CLK.write(SC_LOGIC_0);
			wait(1,SC_NS);
			CLK.write(SC_LOGIC_1);
			wait(1,SC_NS);
			
			wait(CLK.posedge_event());
			
			
			byte=inpA.read();
			cout<<"   "<<byte<<" Sent from B to A  "<<sc_time_stamp()<<endl;
			
			wait(2,SC_NS);
		}
		
		sc_stop();
	}
	
	SC_CTOR(machineA)
	{
		srand(time(NULL));
		SC_THREAD(run);
	}
};