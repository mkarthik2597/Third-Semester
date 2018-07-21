#include"systemc.h"
SC_MODULE(TwotoFour)
{
	sc_in<bool>E,A,B;
	sc_out<bool>sigA0,sigA1,sigA2,sigA3;
	
	void decoderE()
	{
		sigA0.write(E&(1-A.read())&(1-B.read()));
		sigA1.write(E&(1-A.read())&B.read());
		sigA2.write(E&A.read()&(1-B.read()));
		sigA3.write(E&A.read()&B.read());
	}
	
	SC_CTOR(TwotoFour)
	{
		SC_METHOD(decoderE);
		sensitive<<A<<B<<E;
	}
};

SC_MODULE(Enabler)
{
	sc_in<bool>A,B;
	sc_out<bool>sigA0,sigA1,sigA2,sigA3;
	
	void decoder()
	{
		sigA0.write((1-A.read())&(1-B.read()));
		sigA1.write((1-A.read())&B.read());
		sigA2.write(A.read()&(1-B.read()));
		sigA3.write(A.read()&B.read());
	}
	
	SC_CTOR(Enabler)
	{
		SC_METHOD(decoder);
		sensitive<<A<<B;
	}
};


