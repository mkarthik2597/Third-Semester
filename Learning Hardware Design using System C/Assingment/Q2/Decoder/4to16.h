#include"systemc.h"
#include"Ar2to4.h"

SC_MODULE(FourtoSixt)
{
	Enabler Dec1;
	sc_signal<bool> dec10,dec11,dec12,dec13;
	sc_in<bool> w,x,y,z;
	sc_out<bool>D0,D1,D2,D3,D4,D5,D6,D7,D8,D9,D10,D11,D12,D13,D14,D15;
	
	TwotoFour Dec2;
	TwotoFour Dec3;
	TwotoFour Dec4;
	TwotoFour Dec5;
	
	SC_CTOR(FourtoSixt):Dec1("Dec1"),Dec2("Dec2"),Dec3("Dec3"),Dec4("Dec4"),Dec5("Dec5")
	{
		Dec1.sigA0(dec10);
		Dec1.sigA1(dec11);
		Dec1.sigA2(dec12);
		Dec1.sigA3(dec13);
		
		Dec2.E(dec10);
		Dec3.E(dec11);
		Dec4.E(dec12);
		Dec5.E(dec13);
		
		Dec2.A(y);
		Dec2.B(z);
		
		Dec3.A(y);
		Dec3.B(z);
		
		Dec4.A(y);
		Dec4.B(z);
		
		Dec5.A(y);
		Dec5.B(z);
		
		Dec1.A(w);
		Dec1.B(x);
		
		Dec2.sigA0(D0);
		Dec2.sigA1(D1);
		Dec2.sigA2(D2);
		Dec2.sigA3(D3);
		
		Dec3.sigA0(D4);
		Dec3.sigA1(D5);
		Dec3.sigA2(D6);
		Dec3.sigA3(D7);
		
		Dec4.sigA0(D8);
		Dec4.sigA1(D9);
		Dec4.sigA2(D10);
		Dec4.sigA3(D11);
		
		Dec5.sigA0(D12);
		Dec5.sigA1(D13);
		Dec5.sigA2(D14);
		Dec5.sigA3(D15);
		
	}
};
		
		
		

	