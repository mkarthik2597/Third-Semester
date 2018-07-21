#include"systemc.h"
#include"print.h"
#include"Driver.h"
int sc_main(int argc, char*argv[])
{
	PrintHello PrintH("PrintH");
	sc_signal<bool>sigclk;
    sc_trace_file *Trace;
	
	PrintH.clk(sigclk);
	driver D1 ("D1");
	D1.clk(sigclk);
	
	sc_clock Tclk("Test",1000,SC_NS,0.5,10,SC_NS);
	D1.Tclk(Tclk);
	
	Trace = sc_create_vcd_trace_file("PrintHello");
    sc_trace(Trace,Tclk, "Simulation_Clock");
	sc_trace(Trace,sigclk, "Control_Clock");
	
	sc_start();
	sc_close_vcd_trace_file(Trace);
}
