#include"systemc.h"
SC_MODULE(Or8)
{
	sc_in<bool>in1,in2,in3,in4,in5,in6,in7,in8;
	sc_out<bool>W;
	
	void orgate()
	{
		W.write(in1.read()|in2.read()|in3.read()|in4.read()|in5.read()|in6.read()|in7.read()|in8.read());
	}
	
	SC_CTOR(Or8)
	{
		SC_METHOD(orgate);
		sensitive<<in1<<in2<<in3<<in4<<in5<<in6<<in7<<in8;
	}
};