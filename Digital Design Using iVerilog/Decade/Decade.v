module decade(reset,clk,A);
input reset,clk;
output reg [3:0] A;

always@(posedge clk, negedge reset)
begin
if(reset==0)
A=0;
else if(A!=4'b1001)                 //This is how you write the behavioral description of a mod-n counter
A=A+1;
else
A=0;
end

endmodule