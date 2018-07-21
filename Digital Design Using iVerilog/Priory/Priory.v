module priory(D,A);
input wire [3:0] D;
output reg [1:0] A; //You can't use wire data type while assigning in an always block

always@(D)          //Behavioral modelling for a combinational ckt:  always@(all_i/ps). The truth table is written as else if ladder
begin
if(D[3]==1)
A=2'b11;
else if(D[2]==1)
A=2'b10;
else if(D[1]==1)
A=2'b01;
else
A=2'b00;

end
endmodule
