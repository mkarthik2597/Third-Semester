module lsr(clk,sin,A,reset);
input sin,clk,reset;
output reg [3:0] A;

always@(posedge clk,negedge reset)
begin
if(reset==0)
A=4'b0000;
else
A={A[2:0],sin};
end

endmodule