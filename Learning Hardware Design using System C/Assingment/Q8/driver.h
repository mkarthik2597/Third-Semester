#include"systemc.h"
SC_MODULE(driver)
{
	
	sc_in<bool>clk;
	sc_out<bool>DOut;
	
	void run()
	{
		int value=1765;
		for(int i=0;i<=16;i++)
		{
			bool bit=(value>>i)&1;
			DOut.write(bit);
			cout<<"\n";
			wait();
		}
		sc_stop();
	}
	
	SC_CTOR(driver)
	{
		SC_THREAD(run);
		sensitive<<clk.pos();
	}
};
	
	