#Functions in python
#Function are to be defined before the calls are made. There is no function declaration in Python

def sum(a,b):                  #Note the syntax: def function(arg):
    print "%d+%d=%d" %(a,b,a+b) #An indentation means that this block is a part of the function

def sum_s(*operands):        #The actual arguments are passed to a single entity called as "operands" here
    f,s=operands            #This is the unpacking of variables
    print "%d+%d=%d" %(f,s,f+s)

def mul(a,b):           #You don't need to explicitly mention the return type
    return a*b

def printer():
    print "I only print Hello!"

def fun():
    cars=2
    buses=3
    trucks=4
    return cars,buses,trucks       #Returning multiple variables effortlessly

#Functions can have default arguments as well

def area(radius=1):
    print 3.14*radius*radius

sum(2,3)
sum_s(3,4)
printer()

#Actual arguments to a function
#Direct numbers

#Variables
a=9;b=10
sum(a,b)
sum(4+5,5+5)
sum(b-1,a+1)

print "Addition:"
a=int(raw_input("Enter first number:"))
b=int(raw_input("Enter second number"))
sum(a,b)

print "Multiplication:"
print mul(int(raw_input("Multiplicand:")),int(raw_input("Multiplier:")))
#mul returns a value and we hence print it

print "This is real insane! Cars=%d\nBuses=%d\nTrucks=%d" %fun()

#You can unpack return values this way also
a,b,c=fun()
print a,b,c

area()
area(2)
