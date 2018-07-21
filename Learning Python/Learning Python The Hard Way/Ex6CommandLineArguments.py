# Command line arguments, importing modules

from sys import argv              #import the feature argv(class, function,..) from the sys module
filename,first,second,third=argv

print filename,first,second,third

# The arguments are read as strings. You can convert any of these arguments to integers
# The Command line arguments have to be of type int for the code below to work
# The type cast will work only if you input an integer, otherwise you will have an error

first=int(argv[1])
second=int(argv[2])
third=int(argv[3])
print first+second+third

#Prompting Users.

prompt='$'
print "May I know you name?"
like=raw_input(prompt)

print "Do you like Python?"
like_python=raw_input(prompt)

print "You are %s and you said %s about liking Python" %(like,like_python)
