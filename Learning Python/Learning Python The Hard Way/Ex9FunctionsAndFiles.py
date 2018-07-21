from sys import argv
script,infile=argv

#If f is not passed, you get an error as f is not a global variable
def print_all(f):
    print f.read()

def rewind(f):
    f.seek(0)

def printline(f):
    print f.readline(),   #When you append a comma after the argument list,
                          # you are suppressing the newline character of print.This is needed because
                          # readline will read till and including a newline character and thus will get printed
                          # Just f.readline() will not print anything
                          #f.readlines() will return a list of lines in the file

current_file=open(infile)

print_all(current_file)
rewind(current_file)

printline(current_file)
printline(current_file)
printline(current_file)
