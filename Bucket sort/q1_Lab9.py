s = input()
input_lst = s.split()
input_lst[0] = int(input_lst[0])
N = input_lst[0]
input_lst[1] = int(input_lst[1])
m = input_lst[1]


for i in range(2,len(input_lst)):
    input_lst[i] = float(input_lst[i])

def bucketSort(arr,m):
    # first make a new bucket
    bucket = [[] for i in range(m)]
    # looping over the main array, enter its elements into bucket[arr[i]*m]
    for i in arr:
        index_to_be_entered = int(i*m)
        bucket[index_to_be_entered].append(i)

    # have to print this mapped version
    for i in range(m-1,-1,-1):
        print_arr(bucket[i])
        # print(*bucket[i])
        # print()
    # sorting each of the buckets
    for i in range(m):
        bucket[i] = insertionSort(bucket[i])
    for i in range(m-1,-1,-1):
        # print(*bucket[i])
        print_arr(bucket[i])
    # k = 0
    final_arr=[]
    for i in range(m-1,-1,-1):
        for j in range(len(bucket[i])):
            final_arr.append(bucket[i][j])
            # k+=1
    print_arr(final_arr)


def insertionSort(arr):
    for i in range(1, len(arr)):
        temp = arr[i]
        j = i-1
        while j >= 0 and arr[j] < temp:
            arr[j+1] = arr[j]
            j-= 1
        arr[j+1] = temp   
    return arr

def print_arr(arr):
    for i in range(len(arr)):
        if(i==len(arr)-1):
            print(arr[i],end='')
            print()
        else:
            print(arr[i], end=" ")
    


bucketSort(input_lst[2:], m)
