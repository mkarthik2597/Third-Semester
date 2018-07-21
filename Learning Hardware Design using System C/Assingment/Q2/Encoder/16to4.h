#include"Or4.h"
#include"systemc.h"
SC_MODULE(Encoder)
{
	sc_in<bool>D0,D1,D2,D3,D4,D5,D6,D7,D8,D9,D10,D11,D12,D13,D14,D15;
	sc_out<bool>w,x,y,z;
	Or8 or1;
	Or8 or2;
	Or8 or3;
	Or8 or4;
	

  SC_CTOR(Encoder):or1("or1"),or2("or2"),or3("or3"),or4("or4")
	{
	
	or1.in1(D8);
	or1.in2(D9);
	or1.in3(D10);
	or1.in4(D11);
	or1.in5(D12);
	or1.in6(D13);
	or1.in7(D14);
	or1.in8(D15);
	
	or1.W(w);
	
	or2.in1(D4);
	or2.in2(D5);
	or2.in3(D6);
	or2.in4(D7);
	or2.in5(D12);
	or2.in6(D13);
	or2.in7(D14);
	or2.in8(D15);
	
	or2.W(x);
	
	or3.in1(D2);
	or3.in2(D3);
	or3.in3(D6);
	or3.in4(D7);
	or3.in5(D10);
	or3.in6(D11);
	or3.in7(D14);
	or3.in8(D15);
	
	or3.W(y);
	
	or4.in1(D1);
	or4.in2(D3);
	or4.in3(D5);
	or4.in4(D7);
	or4.in5(D9);
	or4.in6(D11);
	or4.in7(D13);
	or4.in8(D15);
	
	or4.W(z);
  }
}; 
 