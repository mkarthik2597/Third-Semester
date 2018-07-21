#include"systemc.h"
SC_MODULE(monitor)
{
	sc_in<bool> A,B,F,clk;
	void output()
	{
		cout<<A.read()<<" "<<B.read()<<" "<<"  "<<F.read()<<endl;
	}
	
	SC_CTOR(monitor)
	{
		SC_METHOD(output);
		sensitive<<clk.pos();
	}
};
