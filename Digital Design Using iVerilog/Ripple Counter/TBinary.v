`timescale 1ns/1ps
module Rcounter;
reg clk,reset;
output [0:3] count;

TFF t1(.clk(clk), .Q(count[3]), .reset(reset));
TFF t2(.clk(count[3]), .Q(count[2]), .reset(reset));
TFF t3(.clk(count[2]), .Q(count[1]), .reset(reset));
TFF t4(.clk(count[1]), .Q(count[0]), .reset(reset));

integer i;

initial begin
reset=0;
#5
reset=1;

clk=0;
for(i=0;i<=15;i++)
#5 clk=~clk;

end

initial begin
$monitor("%4b",count);
end

endmodule