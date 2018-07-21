`timescale 1ns/100ps
module t_HA;

reg a,b;            //Registers, because we assign values to them, they drive inputs
wire cout,sum;
HA HA1(.a(a), .b(b), .cout(cout), .sum(sum));

initial begin
$dumpfile("gtkHA.vcd");
$dumpvars(a,b,cout,sum);
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
$monitor("a=%d b=%d  sum=%d carry=%d",a,b,sum,cout);   //You needn't use "\n" in the montitor function

endmodule