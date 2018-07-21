`timescale 1ns/100ps
module t_JK;
reg J,K,clk;
wire Q;
JK jk(.J(J), .K(K), .clk(clk), .Q(Q));

initial begin
$dumpfile("gtkJK.vcd");
$dumpvars(1,t_JK);

J=0;
K=0;
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

integer i;
initial begin
clk=0;
for(i=0;i<=10;i++)            //There are totally 11 half cycles of the clock, 6 negative and 5 positive. Each half cycle lasts for 10s
#10 clk=~clk;

end
endmodule