#Console input

print "How old are you?",  #The comma is for the user to enter the input in the same line as this.
age=raw_input()            #It presents a prompt to the user,
                           #gets input from the user and
                           #returns the data input by the user in a string.

print "What is your height?"
height=raw_input()
print "You are %r years old and %r tall" %(age,height)

print "Enter any number.The output will show double of that number"
num=raw_input()
print 2*num
# Well, that will not happen! The input string will be printed out twice.

print "Okay, programmer error.Try once again!",
print "Enter any number.The output will show double of that number"
num=int(raw_input())
print 2*num
# The input is cast into an int

# You can prompt users by writing inside the raw_input() as shown:

color=raw_input("Enter your favourite colour:")
print "Your favourite colour is %r"%color
movie=raw_input("Enter your favourite movie:"),
print "And your favourite movie is %r"%movie


#Reading multiple inputs in the same line
print "Enter any two numbers:"
a,b=map(int,raw_input().split())
