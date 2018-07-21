module Ucounter(clk,reset,load,binary,load_s);
input clk,reset,load_s;
input [3:0] load;
output reg [3:0] binary;


always@(posedge clk,negedge reset,posedge load_s)
begin
if(reset==0)
binary=0;
else if(load_s==1)
binary=load;
else
binary=binary+1;
end

endmodule