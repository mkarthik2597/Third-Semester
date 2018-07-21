list1=["apple","mango","banana"]
# print list1                           #Prints the list in the list format itself

for i in list1:
    print i

list2=[1,"Buckle",3,"Shut the door"]

for i in list2:
    print i


list3=range(0,6)                #0,1,2,3,4,5
print list3                     #Prints in list format
print "."*20

list3=range(4)                 #0,1,2,3
print list3

list3=range(0,10,2)             #0,2,4,6,8
print list3
print "."*20

list1=[]
for i in list3:
    list1.append(i)              #Appends object i to the end

print list1

list1=[1,1,2,2,2,6,5]
print list1.count(2)              #returns no. of occurrences of 2
print list1.index(2)              #returns the first index of 2
print list1.index(2,0,3)          #Print the occurrence of 2 in the range 0,1,2

list1.insert(1,10)                #Inserts the value 10 before index 1
print list1

print list1.pop(2)                #Returns and removes the item at index 2
print list1
print list1.pop(),list1           #Pops the last element if index is not specified

list1.remove(2)                   #Removes element at index 2. Does not return anything
print list1

list1.remove(6)                   #Removes element 6
print "Random removal:",list1

list1.reverse()                   #Reverses list
print list1
list1.sort()                      #Sorts the array elements
print list1

ListOfSevens=[7]*5                # The list contains 5 7s
print ListOfSevens

print len(ListOfSevens)           #len works for lists also, not only for strings

for letter in "Hello":
    if letter=='l':
        continue                  # Python supports continue statement
    print letter,
