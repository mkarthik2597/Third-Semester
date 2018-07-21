#include "time.h"
#include "systemc.h"
#include "common.h"

SC_MODULE(MachineA)
{
	sc_in< sc_bv<8> >  inpA;
    sc_out< sc_bv<8> > outpA;
    
	sc_inout_resolved CLK;

	void run()
	{
		sc_bv<8> byte;

		while (true) 
		{
			byte = rand() % 256;

			outpA.write(byte);
			cout << "A sent message to B: " << byte <<" Time: "<<sc_time_stamp()<<endl;

			CLK.write(SC_LOGIC_0); wait(1,SC_NS);
			CLK.write(SC_LOGIC_1); wait(1,SC_NS);

			for (int i=0;i<4;i++) 
			{
				wait(CLK.posedge_event());

				byte = inpA.read();
				cout << "A received message from B: " << byte <<" Time: "<<sc_time_stamp()<<endl;
			}
            cout<<"\n\n";
			wait(rand()%5+5, SC_NS);
		}
	}

	SC_CTOR(MachineA)
	{
		srand(time(NULL));
		SC_THREAD(run);
	}
};
