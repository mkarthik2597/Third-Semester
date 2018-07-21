#include "systemc.h"

SC_MODULE(DFlipFlop)
{
    sc_in<bool> D,clk;
    sc_out<bool> Q,Qout;

    void Run()
    {
        Q.write(D.read());
		Qout.write(D.read());
        //QNeg.write(!D.read());
    }

    SC_CTOR(DFlipFlop)
    {
        SC_METHOD(Run);
        sensitive << clk.pos();
    }
};