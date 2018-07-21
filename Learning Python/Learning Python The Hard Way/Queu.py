from Queue import *
Q=Queue(maxsize=10)

while True:
    print "Maxsize of Q is 10\n\nEnter\n1 to enq\n2 to deq\n3 to exit"
    i=int(raw_input())

    if i==1:
        if not Q.full():
            Q.put(int(raw_input("Enter item:")))
        else:
            print "Queue is full"

    elif i==2:
        print Q.get()

    else:
        break
