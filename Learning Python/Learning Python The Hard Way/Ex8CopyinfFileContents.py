#Copy contents from one file to  another

from sys import argv
from os.path import exists

script,from_f,to_f=argv

# input_file=open(from_f)
# indata=input_file.read()
#The default mode in the open function is the read mode
indata=open(from_f).read()

print "The input file is %d bytes long" %len(indata)  #len() is a built in function that is always available
print "Does the output file exist?%r" %exists(to_f)

#exists(to_f) return true or false depending on whether a file exists or not
# output_file=open(to_f,"w")
# output_file.write(indata)

open(to_f,"w").write(indata)

# open(to_f,"w").write(open(from_f).read())
#The above piece of code reduces the entire script size to one line of code.

print "Done"
