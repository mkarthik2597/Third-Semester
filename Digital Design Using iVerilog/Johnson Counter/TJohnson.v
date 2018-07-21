`timescale 1ns/1ps
module t_Johnson;
reg clk,reset;
wire [3:0] A;

Johnson J(.clk(clk),.reset(reset),.A(A));

integer i;

initial
begin
reset=0;
#2
$dumpfile("Johnson.vcd");
$dumpvars(clk,A);
reset=1;

clk=0;
for(i=0;i<=10;i++)
#5 clk=~clk;
end
 

initial
$monitor("%4b",A);

endmodule