module encoder(A,Y1);
input [3:0] A;
output Y1;
encoder_p (Y1,A);                     //Similar to gate level modelling. encoder_p is a gate here.
endmodule

primitive encoder_p (Y1,A);
output Y1;                                 //Define inputs and outputs before writing down the table.
input [3:0] A;
table
0 0 0 1:0;
0 0 1 0:0;
0 1 0 0:1;
1 0 0 0:1;
endtable
endprimitive