`timescale 1ns/1ps
module t_decoder; 
reg a,b;
wire[3:0] D;
decoder D1(.a(a), .b(b), .D(D));

initial begin
$dumpfile("Decoder.vcd");
$dumpvars(a,b,D);
a=0;
b=0;

#20
a=0;
b=1;

#20
a=1;
b=0;

#20
a=1;
b=1;

end

initial 
$monitor ("a=%d b=%d  %4b",a,b,D);

endmodule 