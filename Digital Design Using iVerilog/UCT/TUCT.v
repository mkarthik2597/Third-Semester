module t_Ucounter;
reg clk,reset,load_s;
reg[3:0] load;
wire[3:0] binary;

Ucounter U1(.clk(clk), .reset(reset), .load_s(load_s), .load(load), .binary(binary));

integer i;

initial begin
clk=0;
reset=0;
#2
reset=1;
#30
load_s=1;
load=4'b1010;
#10
load_s=0;
end

initial begin
for(i=0;i<=15;i++)
#10 clk=~clk;
end

initial begin
$monitor("%4b\n",binary);
end

endmodule
