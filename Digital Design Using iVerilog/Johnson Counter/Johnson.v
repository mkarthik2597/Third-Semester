module Johnson(clk,reset,A);
input clk,reset;
output reg [3:0] A;

always@(posedge clk,negedge reset)
begin
if(reset==0)
A=0;
else
A={(~A[0]),A[3:1]}; //{} is the concatenation operator
end

endmodule