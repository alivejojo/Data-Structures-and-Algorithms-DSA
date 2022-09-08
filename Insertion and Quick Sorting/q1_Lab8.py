# input and inital assignment
s = input()
arr = s.split(sep=' ')
arr = [ int(i) for i in arr]

N = arr[0]
T = arr[1]

arr = arr[2:]

# insertion sort of subarray of array - arr frm indices inclusive of start and end index
def insertionSort(arr, start, end):
    i=0
    i = start + 1
    while(i<=end):
        hole = i
        while hole>start and arr[hole-1]>arr[hole]:
            t = arr[hole]
            arr[hole] = arr[hole-1]
            arr[hole-1] = t
            hole = hole-1
        i+=1
        
# this function does 2 things, assigns the last and misplaced element of the subarray from start to end and 
# rearranges the subarray such that all elements smaller than the pivot element are to its left and those
# larger are to its left

def partition(arr,start,end):
    pivot = arr[end]
    pivot_Index = start
    i = start
    while(i<end):
        if(arr[i]<pivot):
            arr[i], arr[pivot_Index] = arr[pivot_Index] , arr[i]
            pivot_Index+=1
        i+=1
    arr[pivot_Index], arr[end] = arr[end], arr[pivot_Index]
    return pivot_Index
    
    
# recursive function with base case of when the length of the subarray is less than the threshold value of T
# when base case is true, that subarray is sorted using insertion_sort()

def quickSort(arr,start, end):
    while(end-start>0):
        if(end-start<T-1):
            # last call
            # only a call and not return as it changes arr itself
            insertionSort(arr,start,end)
            break
        else:

            pivot_Index = partition(arr, start, end)
            if pivot_Index*2-start-end<0:
                quickSort(arr, start, pivot_Index-1)
                start = pivot_Index + 1
            else:
                quickSort(arr, pivot_Index+1, end)
                end = pivot_Index -1           
    print(*arr)

quickSort(arr, 0, N-1)


