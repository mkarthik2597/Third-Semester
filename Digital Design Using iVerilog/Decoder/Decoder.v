module decoder(a,b,D);

input a,b;
output [3:0] D;
wire na,nb;       //We use wires for connecting outputs to inputs in a combinational circuit

not (na,a);
not (nb,b);
and (D[0],na,nb);
and (D[1],na,b);
and (D[2],a,nb);
and (D[3],a,b);

endmodule