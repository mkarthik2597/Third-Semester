`timescale 1ns/1ps
module t_JKD;
reg J,K,clk,reset;
wire Q;

JK_D J1(.J(J), .K(K), .clk(clk), .Q(Q), .reset(reset));
integer i;

initial begin
reset=0;
reset=1;
#8
J=0;K=1;
#10
J=0;K=0;
#10
J=1;K=0;
#10
J=1;K=1;
#10
J=1;K=1;
end

initial begin
clk=0;
for(i=0;i<=10;i++)
#10 clk=~clk;
end

initial
$monitor("%d %d  %d\n",J,K,Q);

endmodule