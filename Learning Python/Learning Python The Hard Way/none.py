foo=3
print foo
foo=None
print foo                                 #"None" gets printed

# == operator checks if two objects are equal an "is" operator checks whether the objects are the same
#The same thing with != and is not as well

if foo is None:
    print "Yes, none"
if foo is not None:
    print "No, not none"

def spam(foo=None):
    if foo is not None:
        print "Default argument over-written"

spam(3)
