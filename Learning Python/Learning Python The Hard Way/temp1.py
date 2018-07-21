print "Enter the number of foreground processes and background processes:"
F,B=map(int,raw_input().split())

ATF=[]
BTF=[]

ATB=[]
BTB=[]

print "Foreground process...\n"
for i in range(0,F):
    AT,BT=map(int,raw_input("Enter AT and BT of %d:" %(i+1)).split())
    ATF.append(AT)
    BTF.append(BT)

print "Background process...\n"
for i in range(0,B):
    AT,BT=map(int,raw_input("Enter AT and BT of %d:" %(i+1)).split())
    ATB.append(AT)
    BTB.append(BT)

print ATF,BTF,ATB,BTB
