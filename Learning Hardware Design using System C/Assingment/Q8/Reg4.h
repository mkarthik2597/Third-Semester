#include"flipflop.h"
#include"systemc.h"
SC_MODULE(Reg4)
{
	DFlipFlop D0;
	DFlipFlop D1;
	DFlipFlop D2;
	DFlipFlop D3;
	
	sc_in<bool>inp,clk;
	sc_out<bool>out0,out1,out2,out3,out3nxt;
	
	sc_signal<bool>sigA1,sigA2,sigA3;
	
	SC_CTOR(Reg4) : D0("D0"),D1("D1"),D2("D2"),D3("D3")
	{
		D0.D(inp);
		D0.clk(clk);
		D0.Q(sigA1);
		D0.Qout(out0);
		
		D1.D(sigA1);
		D1.clk(clk);
		D1.Q(sigA2);
		D1.Qout(out1);
		
		D2.D(sigA2);
		D2.clk(clk);
		D2.Q(sigA3);
		D2.Qout(out2);

		D3.D(sigA3);
		D3.clk(clk);
		D3.Q(out3nxt);
		D3.Qout(out3);
    }
};