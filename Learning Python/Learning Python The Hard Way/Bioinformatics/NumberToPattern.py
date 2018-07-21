def NoToSymb(num):
    if num==0:
        return "A"
    elif num==1:
        return "C"
    elif num==2:
        return "G"
    else:
        return "T"

A=[]

def NumberToPattern(Index,k):
    if k==1:
        A.append(NoToSymb(Index))
        return

    NumberToPattern(Index//4,k-1)
    A.append(NoToSymb(Index%4))


NumberToPattern(5818,7)
for i in A:
    print i,
