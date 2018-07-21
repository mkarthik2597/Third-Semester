#include"systemc.h"
SC_MODULE(driver)
{
	sc_in<bool>Tclk;
	sc_out<bool>clk;
	
	void drive()
	{
		int i;
		for(i=0;i<100;i++)
		{
			clk.write(true);
			cout<<"Clock cycle:"<<i;
			wait(5,SC_NS);
			
			clk.write(false);
			wait(5,SC_NS);
		}
		
		sc_stop();
	}
	
	SC_CTOR(driver)
	{
		SC_THREAD(drive);
		sensitive<<Tclk.pos();
	}
};
			