module FA(a,b,cin,sum,cout);
input a,b,cin;
output sum,cout;

/*Data flow description*/
assign sum=a^b^cin;                    //We use assign in data flow modelling. assign keyword is applicable only for wire data types
assign cout=(a&b)|(b&cin)|(cin&a);

endmodule

