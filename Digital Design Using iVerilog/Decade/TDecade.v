`timescale 1ns/1ps
module t_decade;
reg clk,reset;
wire [3:0] A;

decade BCD(.clk(clk),.reset(reset),.A(A));
integer i;

initial
begin

reset=0;
reset=1;

clk=0;
for(i=0;i<=20;i++)
#5 clk=~clk;

end

initial
$monitor("%4b\n",A);

endmodule