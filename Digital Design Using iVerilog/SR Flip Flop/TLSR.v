`timescale 1ns/1ps
module t_lsr;
reg sin,clk,reset;
wire [3:0] A;

lsr LSR(.sin(sin), .clk(clk), .reset(reset), .A(A));
integer i;

initial begin
clk=0;
for(i=0;i<=4;i++)
#10 clk=~clk;
end

initial begin
$dumpfile("LSR.vcd");
$dumpvars(0,t_lsr);
reset=0;
#2                            //Always give a pause after resetting
reset=1;

sin=0;
#8
sin=1;
#8
sin=0;
#8
sin=0;
#8
sin=1;
end

initial
$monitor("%4b",A);

endmodule