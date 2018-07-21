#include"systemc.h"
SC_MODULE(monitor)
{
	sc_in<bool>out0,out1,out2,out3,clk;
	void output()
	{
		cout<<out0.read()<<out1.read()<<out2.read()<<out3.read();
	}
	
	SC_CTOR(monitor)
	{
		SC_METHOD(output);
		sensitive<<clk.pos();
	}
};
		