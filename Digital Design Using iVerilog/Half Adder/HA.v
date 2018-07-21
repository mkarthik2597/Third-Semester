module HA(a,b,cout,sum);
input a,b;                 //If data type is not specified, it is a wire 
output cout,sum;

and (cout,a,b);           //Gates need not be named     
xor (sum,a,b);

endmodule
