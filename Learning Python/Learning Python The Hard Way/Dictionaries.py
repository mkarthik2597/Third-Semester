#Initialisng a dictionary

person={"name":"Karthik","age":19,"Branch":"CS"}
print person                                   #Printing the dict
print "Karthik's age is",person["age"]         #Accessing elements of a dict

person["City"]="Bengaluru"   #Makes a new key:value pair. The syntax is not person["City":"Bengaluru"]
print person

del person["age"]            #Delete a key:value pair from a dict
print person


State={"Michigan":"MI","California":"CAL","NewDelhi":"NDL"}
City={"MI":"Minnesotta","CAL":"NewYork"}

print City[State["Michigan"]]

for state,abbr in State.items():       #Iterating through a dictionary
    print "%s:%s" %(state,abbr)

array={}  #Declare an empty dictionary
array["arr"]=[]              #Create an array within a dictionary

array["n"]=int(raw_input("Enter the number of elements in your array:"))
print "Enter the elements"

for i in range(array["n"]):
    array["arr"].append(int(raw_input()))

print array["arr"]
