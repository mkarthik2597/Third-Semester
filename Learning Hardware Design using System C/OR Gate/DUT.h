#include"systemc.h"
SC_MODULE(or2)
{
	sc_in<bool> A,B;
	sc_out<bool> W;
	
	void orgate()
	{
		W.write(A.read()|B.read());
	}
	 
	SC_CTOR(or2)
	{
		SC_METHOD(orgate);
		sensitive<<A<<B;
	}
};
