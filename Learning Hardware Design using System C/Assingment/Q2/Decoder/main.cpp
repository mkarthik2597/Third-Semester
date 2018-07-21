#include"systemc.h"
#include"driver.h"
#include"monitor.h"
#include"4to16.h"
int sc_main(int argc, char*argv[])
{
	sc_signal<bool> wA,xB,yC,zD;
	sc_clock clk("TestClk", 10, SC_NS, 0.5, 10, SC_NS);
	sc_trace_file *Trace;
	Trace = sc_create_vcd_trace_file("Decoder");
	

    driver Driver("D1");
	Driver.clk(clk);
	Driver.A(wA);
	Driver.B(xB);
	Driver.C(yC);
	Driver.D(zD);
	
	FourtoSixt DUT("DUT");
	DUT.w(wA);
	DUT.x(xB);
	DUT.y(yC);
	DUT.z(zD);
	
	monitor mon("Mon");
	mon.clk(clk);
	mon.w(wA);
	mon.x(xB);
	mon.y(yC);
	mon.z(zD);
	
	sc_signal<bool>D0,D1,D2,D3,D4,D5,D6,D7,D8,D9,D10,D11,D12,D13,D14,D15;
	DUT.D0(D0);
	DUT.D1(D1);
    DUT.D2(D2);
	DUT.D3(D3);
	DUT.D4(D4);
	DUT.D5(D5);
	DUT.D6(D6);
	DUT.D7(D7);
	DUT.D8(D8);
	DUT.D9(D9);
	DUT.D10(D10);
	DUT.D11(D11);
	DUT.D12(D12);
	DUT.D13(D13);
	DUT.D14(D14);
	DUT.D15(D15);
	
	mon.D0(D0);
	mon.D1(D1);
    mon.D2(D2);
	mon.D3(D3);
	mon.D4(D4);
	mon.D5(D5);
	mon.D6(D6);
	mon.D7(D7);
	mon.D8(D8);
	mon.D9(D9);
	mon.D10(D10);
	mon.D11(D11);
	mon.D12(D12);
	mon.D13(D13);
	mon.D14(D14);
	mon.D15(D15);
	
    sc_trace(Trace, clk, "clk");
    sc_trace(Trace, wA, "A");
    sc_trace(Trace, xB, "B");
    sc_trace(Trace, yC, "C");
	sc_trace(Trace, zD, "D");
	sc_trace(Trace, D0, "D0");
	sc_trace(Trace, D1, "D1");
	sc_trace(Trace, D2, "D2");
	sc_trace(Trace, D3, "D3");
	sc_trace(Trace, D4, "D4");
	sc_trace(Trace, D5, "D5");
	sc_trace(Trace, D6, "D6");
	sc_trace(Trace, D7, "D7");
	sc_trace(Trace, D8, "D8");
	sc_trace(Trace, D9, "D9");
	sc_trace(Trace, D10, "D10");
	sc_trace(Trace, D11, "D11");
	sc_trace(Trace, D12, "D12");
	sc_trace(Trace, D13, "D13");
	sc_trace(Trace, D14, "D14");
	sc_trace(Trace, D15, "D15");
	sc_start();
	sc_close_vcd_trace_file(Trace);
}
