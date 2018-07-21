#Printing in Python

My_name="Karthik M"        # There is no end of statement marker in python
print My_name              # Directly printable
print My_name[5]           # Will print the character at index 5

print "My name %s is embedded in double quotes" %My_name        # Printing a variable embedded in double quotes
print 'My name %s is now inside single quotes :)' %My_name        # You can use single/doule quotes
print "%s" %"These sort of things work too!"
print "My name's Karthik"  #print 'My name's Karthik'  #Invalid syntax

print "." *20

age=19
print "%s's age is %d" %(My_name,age) # Multiple variables embedded in a string
print "%d+%d is %d" %(age,3,age+3)    #You can do arithmetic inside arguments

print "."*20

x="My name is %s" %My_name  # You can assign a formatted string to a variable
print x                     # and then pass that variable to the print function
print "This is magical:%s" %x
z="This is %s"
y="INSANE!"
print z%y

x="My name is\nKarthik M"
print "%r" %x               # %r prints out raw data, the string x as it is and enclosed within ''
print "%s" %x
print "." *20           # Prints the content 10 times


cheese="Cheese"
burger="Burger"
print cheese+burger       # + acts like a string concatenator

print cheese,             # Comma ensures that "burger" prints on the same line.
print burger              #A space is added after "Cheese"

print "." *20

print """
You should print this out
                      exact this way
"""
print '''
Triple single quotes
                   also just work fine :) '''

#print "You cannot
#           do it with double quotes"
#This is because indentation is a syntactical feauture of Python
a="""You can do this
           as well"""
print a

#You can print multiple variables in a single line as well

a=1
b=2
print a,b
