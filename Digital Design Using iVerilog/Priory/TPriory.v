`timescale 1ns/1ps
module t_priory;
reg [3:0] D;
wire [1:0] A;

priory P1(.D(D), .A(A));

integer i;
initial begin
for(i=0;i<=15;i++)                //Using a for loop for test bench of a combinational ckt
#2 D=i;
end

initial begin
$monitor("D=%4b  A=%2b",D,A);    
end

endmodule