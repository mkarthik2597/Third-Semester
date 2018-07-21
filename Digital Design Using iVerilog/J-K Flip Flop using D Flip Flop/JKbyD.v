module JK_D(J,K,clk,Q,reset);
input J,K,clk,reset;
output reg Q;

wire w1,w2,w3,w4;

and(w1,J,(~Q));         //The combinational part gets executed whenever there is a change in the gate inputs
not(w2,K);
and(w3,Q,w2);
or(w4,w1,w3);

always@(posedge clk,negedge reset)
begin
if(reset==0)
Q=0;
else
Q=w4;
end

endmodule