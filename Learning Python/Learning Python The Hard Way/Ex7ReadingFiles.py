# Reading files

from sys import argv
script,filename=argv

# If the text file is not there in the same folder as the code here,
# you need to specify the file path in the command line itself
txt=open(filename,"r")
#txt is like a file pointer
#Python file modes
# r-read
# w-write
# a-append
# r+w-read and write
print "The contents of the file now are:"
print txt.read()

#read() is a function. txt.read() will return the entire contents of the
#file as it is. You can even assign it to a variable and then print out the contents.

txt.close()

txt=open(filename,"w")
#Opening a file in the write mode will truncate the file size to 0 bytes.
print "This file is now going to be erased.",
print "If you don't want that,hit ctrl+C, else hit RETURN"
raw_input(">>")          #Similar to getchar()

#The truncate here is redundant
txt.truncate()

print "The file is now emptied"
print "Enter a couple of lines now"
line1=raw_input("Line1")
line2=raw_input("line2")

txt.write("%s\n%s"%(line1,line2))
#txt.write("Pass a string!")

print "Thank you"
# l=txt.readline()
# print "1st line:%s" %l

txt.close()                 # Close function for opened files
