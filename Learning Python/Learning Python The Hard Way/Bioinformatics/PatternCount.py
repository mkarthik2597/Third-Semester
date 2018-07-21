# from sys import argv
# script,filename=argv

fd=open("Dataset.txt")
Text,Pattern=fd.readlines()

# print len(Text)
# if Text[6:6+len(Pattern)-1]==Pattern[:-1]:
#     print "Yes"

count=0
for i in range(len(Text)-len(Pattern)+1):
    if Text[i:i+len(Pattern)-1]==Pattern[:-1]:
         count+=1
         #print i+1,

print "  count=",count
