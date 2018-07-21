#include"systemc.h"
SC_MODULE(PrintHello)
{
	sc_in<bool>clk;
	void run()
	{
		cout<<" Hello World\n";
	}
	
	SC_CTOR(PrintHello)
	{
		SC_METHOD(run);
		sensitive<<clk.pos();
	}
};