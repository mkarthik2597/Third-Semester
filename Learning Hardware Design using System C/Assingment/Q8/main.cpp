#include"systemc.h"
#include"Reg4.h"
#include"driver.h"
#include"monitor.h"

int sc_main(int argc,char*argv[])
{
	Reg4 regA("regA");
	Reg4 regB("regB");
	Reg4 regC("regC");
	Reg4 regD("regD");
	
	driver D("D");
	
	monitor monA("monA");
	monitor monB("monB");
	monitor monC("monC");
	monitor monD("monD");
	
	sc_signal<bool>sig0,sig1,sig2,sig3,sig4,sig5,sig6,sig7,sig8,sig9,sig10,sig11,sig12,sig13,sig14,sig15;
	sc_signal<bool>sigIn1,sigIn2,sigIn3,sigIn4,sigIn5;
	sc_clock clk("Test",10,SC_NS,0.5,5,SC_NS);
	
	regA.inp(sigIn1);
	regA.clk(clk);
	regA.out0(sig0);
	regA.out1(sig1);
	regA.out2(sig2);
	regA.out3(sig3);
	regA.out3nxt(sigIn2);
	
	regB.inp(sigIn2);
	regB.clk(clk);
	regB.out0(sig4);
	regB.out1(sig5);
	regB.out2(sig6);
	regB.out3(sig7);
	regB.out3nxt(sigIn3);
	
	regC.inp(sigIn3);
	regC.clk(clk);
	regC.out0(sig8);
	regC.out1(sig9);
	regC.out2(sig10);
	regC.out3(sig11);
	regC.out3nxt(sigIn4);

	regD.inp(sigIn4);
	regD.clk(clk);
	regD.out0(sig12);
	regD.out1(sig13);
	regD.out2(sig14);
	regD.out3(sig15);
	regD.out3nxt(sigIn5);
	
	D.DOut(sigIn1);
	D.clk(clk);
	
	monA.out0(sig0);
	monA.out1(sig1);
	monA.out2(sig2);
	monA.out3(sig3);
	monA.clk(clk);
	
	monB.out0(sig4);
	monB.out1(sig5);
	monB.out2(sig6);
	monB.out3(sig7);
	monB.clk(clk);

	monC.out0(sig8);
	monC.out1(sig9);
	monC.out2(sig10);
	monC.out3(sig11);
	monC.clk(clk);
	
	monD.out0(sig12);
	monD.out1(sig13);
	monD.out2(sig14);
	monD.out3(sig15);
	monD.clk(clk);
	
	sc_start();
}
	
	
	