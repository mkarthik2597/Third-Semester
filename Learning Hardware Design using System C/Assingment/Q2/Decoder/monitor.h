#include"systemc.h"
SC_MODULE(monitor)
{
	sc_in<bool>w,x,y,z,D0,D1,D2,D3,D4,D5,D6,D7,D8,D9,D10,D11,D12,D13,D14,D15,clk;
	void output()
	{
		cout<<w.read()<<x.read()<<y.read()<<z.read()<<"   ";
		cout<<D0.read()<<D1.read()<<D2.read()<<D3.read()<<D4.read();
		cout<<D5.read()<<D6.read()<<D7.read()<<D8.read()<<D9.read();
		cout<<D10.read()<<D11.read()<<D12.read()<<D13.read()<<D14.read()<<D15.read()<<endl;
	}
	
	SC_CTOR(monitor)
	{
		SC_METHOD(output);
		sensitive<<clk.pos();
	}
};
