
n = 0
arr=[]
def Heap_grow():
    global n, arr
    s = n//2-1 
    for i in range(s, -1, -1):
        min_heapify_array(i)

def min_heapify_array(i):
    global n,arr
    smaller = i  
    l = 2*i + 1  
    r = 2*i + 2  
 
    if l < n and arr[l] < arr[smaller]:
        smaller = l
 
    if r < n and arr[r] < arr[smaller]:
        smaller = r
 
    if smaller != i:
        arr[i], arr[smaller] = arr[smaller], arr[i]
        # swap and call again
        min_heapify_array(smaller)

def operate():
    global n, arr
    s=input()
    while(s[-1]==' '):
        s=s[:-1]
    # print(s)
    lst = s.split(" ")
    lst = [int(i) for i in lst]
    # print(lst)

    
    if(lst[0] == 1):
        n = lst[1]
        # print("menu 1:")
        arr = lst[2:]
        # print(arr)
        Heap_grow()
        for i in range(n):
            if(i==n-1):
                print(arr[i])
            else:
                print(arr[i] , end= " ")

        
        operate()

    if(lst[0]==2):
        if(n==0):
            print("Heap does not exist")
            operate()
            return
        else:
            # print("menu 2: insert element")
            m = lst[1] #element to be inserted.. append this to the end of the array and again heapify
            arr.append(m)
            n = n+1
            Heap_grow()
            for i in range(n):
                if(i==n-1):
                    print(arr[i])
                else:
                    print(arr[i] , end= " ")
            operate()

    if(lst[0]==3):
        #delete the root node
        if(n<=0):
            print("Heap does not exist")
            operate()
        else:
            n=n-1
            arr[0] = arr[-1]
            arr = arr[:-1]
            Heap_grow()
            for i in range(n):
                if(i==n-1):
                    print(arr[i])
                else:
                    print(arr[i] , end= " ")
            operate()
    
    if(lst[0]==4):
        # enter a number and delete it
        if(n<=0):
            print("Heap does not exist")
            operate()
        else:
            # n=n-1
            m = lst[1]
            j=-1
            for i in range(0,len(arr)):
                
                if(arr[i]==m):
                    j=i
            if(j==-1):
                print("Integer not found")
                operate()

            else:
                n=n-1
                arr[j] = arr[-1]
                arr = arr[:-1]
                Heap_grow()
                for i in range(n):
                    if(i==n-1):
                        print(arr[i])
                    else:
                        print(arr[i] , end= " ")
                operate()

    if(lst[0]==5):
        '''
        swap root and last element
        decrease n by 1
        heapify the smaller tree
        keep doing this till n == 1
        '''
        while(n!=1):
            arr[0],arr[n-1] = arr[n-1],arr[0]
            # print("swap done")
            # print(arr)
            n=n-1
            Heap_grow()
            # print("heapify done")
            # print(arr)
        
        
        for i in range(len(arr)):
            if(i!=len(arr)-1):
                print(arr[i], end = " ")
            else:
                print(arr[i])
        operate()
        
    if(lst[0]==-1):
        return 0


operate()

