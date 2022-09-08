max_size = int(input())
front = -1
rear = 0
counter = 0
q = [0 for i in range(max_size)]
s = input()
counter = 0
flag = 0

def operate(s):

    global q,front,rear,counter,max_size, counter, flag
    while(s[-1]==' '):
        s=s[:-1]

    lst = s.split(" ")
    lst = [int(i) for i in lst]

    if(lst[0]==1):
        
        if(counter==max_size):
            print("overflow")
            s = input()
            operate(s)
        else:
            if(lst[1]>max_size - counter):
                print("overflow")
                s = input()
                operate(s)

            else:
                for i in range(lst[1]):
                    if(front==-1):
                        front = 0
                        q[rear] = lst[2+i]
                        counter+=1
                    elif(q[front]==0 and rear==front):
                        q[front] = lst[i+2]
                        counter+=1                        
                    else:
                        rear = (rear+1)%max_size
                        q[rear] = lst[2+i]
                        counter+=1
        print(*q)
        s = input()
        operate(s)
    
    elif(lst[0]==2):
        
        if(counter==0):
            print("underflow")
            s = input()
            operate(s)
        
        else:
            if (lst[1]>counter):
                print("underflow")
                s = input()
                operate(s)
            
            else:
                for i in range(lst[1]):
                    q[front] = 0
                    counter-=1
                    if(counter==0):
                        pass
                    else:
                        front = (front+1)%max_size
        print(*q)
        s = input()
        operate(s)
    
    elif (lst[0]==3):
        if(front==-1):
            print("underflow")
            s = input()
            operate(s)
        # elif(counter==0):
        #     print("underflow")
        #     s = input()
        #     operate(s)
        else:
            print(q[front], front)
            print(q[rear], rear)
            print(counter)
        print(*q)
        s = input()
        operate(s)

    else:
        import sys
        sys.exit()

operate(s)


