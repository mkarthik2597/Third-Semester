module JK(J,K,clk,Q);
input wire J,K,clk;
output reg Q;

always@(posedge clk)
begin
if(J==1&&K==0)
Q=1;
else if(J==0&&K==1)
Q=0;
else if(J==1&&K==1)
Q=~Q;
else
Q=Q;
end

endmodule