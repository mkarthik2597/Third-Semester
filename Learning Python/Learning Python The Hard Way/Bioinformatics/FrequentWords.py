fd=open("Dataset.txt")
Text,k=fd.readlines()
k=int(k)
# print Text
# print k
#

kmers=[]
count_k=[]
check=[0]*(len(Text)-k+1)
max_i=0

for i in range(len(Text)-k+1):
    if check[i]==1:
      continue

    count=0
    for j in range(i,len(Text)-k+1):
        if Text[j:j+k]==Text[i:i+k]:
            count+=1
            check[j]=1

    kmers.append(Text[i:i+k])
    count_k.append(count)

    if(count>count_k[max_i]):
        max_i=len(kmers)-1

for i in range(max_i,len(count_k)):
    if count_k[i]==count_k[max_i]:
        print kmers[i],count_k[i]
