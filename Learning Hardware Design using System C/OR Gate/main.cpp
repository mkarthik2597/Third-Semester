#include "systemc.h"
#include "DUT.h"
#include "Driver.h"
#include "monitor.h"

int sc_main(int argc, char*argv[])
{
	sc_signal<bool> A,B,W;
	sc_clock clk("TestClk", 10, SC_NS, 0.5, 10, SC_NS);
	sc_trace_file *Trace;

	driver D1("D1");
	D1.A(A);
	D1.B(B);
	D1.clk(clk);
	
	or2 OR("OR");
	OR.A(A);
	OR.B(B);
	OR.W(W);
	
	monitor MON("MON");
	MON.A(A);
	MON.B(B);
	MON.F(W);
	MON.clk(clk);
	
    Trace = sc_create_vcd_trace_file("FullAdder");
    sc_trace(Trace, A, "A");
    sc_trace(Trace, B, "B");
    sc_trace(Trace, W, "W");
   
    sc_start();
    sc_close_vcd_trace_file(Trace);

    return 0;
}