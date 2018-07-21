`timescale 1ns/1ps
module t_FA;
reg a,b,cin;
wire sum,cout;

FA FA1
(.a(a),.b(b), .cin(cin), .sum(sum), .cout(cout));

initial 
begin
a=0;
b=0;
cin=0;

#20
a=0;
b=0;
cin=1;

end

initial 
$monitor("x=%d,y=%d,cin=%d  sum=%d,cout=%d",a,b,cin,sum,cout);

endmodule
