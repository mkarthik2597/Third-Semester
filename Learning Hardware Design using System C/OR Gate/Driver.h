#include"systemc.h"
SC_MODULE(driver)
{
	sc_in<bool> clk;
	sc_out<bool> A,B;
	
	void stimulate()
	{
		A.write(false);
		B.write(false);
		wait();
		A.write(false);
		B.write(true);
		wait();
		A.write(true);
		B.write(false);
		wait();
		A.write(true);
		B.write(true);
		wait();
		sc_stop();
	}
	
	SC_CTOR(driver)
	{
		SC_THREAD(stimulate);
		sensitive<<clk.pos();
	}
};
	