module TFF(clk,Q,reset);
input clk,reset;
output reg Q;

always @(negedge clk, negedge reset) /*An if else statement need not have a begin and an end, just as in C*/
if(reset==0)
Q=0;
else
Q=~Q;

endmodule