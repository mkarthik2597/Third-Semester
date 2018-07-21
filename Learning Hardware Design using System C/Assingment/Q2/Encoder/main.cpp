#include"systemc.h"
#include"monitor.h"
#include"driver.h"
#include"16to4.h"
int sc_main(int argc, char*argv[])
{
	sc_clock clk("TestClk", 10, SC_NS, 0.5, 10, SC_NS);
	sc_trace_file *Trace;
	Trace = sc_create_vcd_trace_file("Encoder");
	sc_signal<bool>S0,S1,S2,S3,S4,S5,S6,S7,S8,S9,S10,S11,S12,S13,S14,S15;
    driver Drive("Drive");
    Drive.clk(clk); 
	Drive.D0(S0); 
	Drive.D1(S1);
	Drive.D2(S2);
	Drive.D3(S3);
	Drive.D4(S4);
	Drive.D5(S5);
	Drive.D6(S6);
	Drive.D7(S7);
	Drive.D8(S8);
	Drive.D9(S9);
	Drive.D10(S10);
	Drive.D11(S11);
	Drive.D12(S12);
	Drive.D13(S13);
	Drive.D14(S14);
	Drive.D15(S15);
	
	Encoder enc1("enc1");
	enc1.D0(S0);
	enc1.D1(S1);
	enc1.D2(S2);
	enc1.D3(S3);
	enc1.D4(S4);
	enc1.D5(S5);
	enc1.D6(S6);
	enc1.D7(S7);
	enc1.D8(S8);
	enc1.D9(S9);
	enc1.D10(S10);
	enc1.D11(S11);
	enc1.D12(S12);
	enc1.D13(S13);
	enc1.D14(S14);
	enc1.D15(S15);
	
	sc_signal<bool>sw,sx,sy,sz;
	enc1.w(sw);
	enc1.x(sx);
	enc1.y(sy);
	enc1.z(sz);
	
	monitor mon("mon");
	mon.clk(clk);
	mon.D0(S0); 
	mon.D1(S1);
	mon.D2(S2);
	mon.D3(S3);
	mon.D4(S4);
	mon.D5(S5);
	mon.D6(S6);
	mon.D7(S7);
	mon.D8(S8);
	mon.D9(S9);
	mon.D10(S10);
	mon.D11(S11);
	mon.D12(S12);
	mon.D13(S13);
	mon.D14(S14);
	mon.D15(S15);
	
	mon.w(sw);
	mon.x(sx);
	mon.y(sy);
	mon.z(sz);
	
	sc_trace(Trace,clk, "clk");
	
	sc_trace(Trace,S0,"D0");
	sc_trace(Trace,S1,"D1");
	sc_trace(Trace,S2,"D2");
	sc_trace(Trace,S3,"D3");
	sc_trace(Trace,S4,"D4");
	sc_trace(Trace,S5,"D5");
	sc_trace(Trace,S6,"D6");
	sc_trace(Trace,S7,"D7");
	sc_trace(Trace,S8,"D8");
	sc_trace(Trace,S9,"D9");
	sc_trace(Trace,S10,"D10");
	sc_trace(Trace,S11,"D11");
	sc_trace(Trace,S12,"D12");
	sc_trace(Trace,S13,"D13");
	sc_trace(Trace,S14,"D14");
	sc_trace(Trace,S15,"D15");
	
	sc_trace(Trace,sw,"w");
	sc_trace(Trace,sx,"x");
	sc_trace(Trace,sy,"y");
	sc_trace(Trace,sz,"z");
	
	sc_start();
	sc_close_vcd_trace_file(Trace);
}
	
 	
	