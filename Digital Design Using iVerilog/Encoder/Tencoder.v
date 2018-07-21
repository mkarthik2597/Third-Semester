`timescale 1ns/1ps
module t_encoder;
reg [3:0] A;
wire Y1;
encoder C1
(
 .A(A), .Y1(Y1)
);

initial begin
A=1;               //Assignment can be in binary or in bits: A=4'b0001
#2
A=2;
#2
A=4;
#2
A=8;
end

initial begin
$monitor("%d%d%d%d %d\n",a,b,c,d,Y1);
end
endmodule
