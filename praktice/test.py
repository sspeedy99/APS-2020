def checkIsFibonacci(arr, n) :
 
    if (n == 1 or n == 2) :
        return True
 
    # Sort array
    arr.sort()
    for i in range(2, n) :
        if ((arr[i - 1] +
             arr[i - 2])!= arr[i]) :
            return False
 
    return True


def solve(arr,n):
    diff = arr[1] - arr[0]
    ratio = arr[1] / arr[0]
    arith = True
    geo = True
    
    for i in range(0, n-1):
        if( arr[i + 1] - arr[i] != diff ):
            arith = False
        if(arr[i + 1] / ratio != arr[i]):
            geo = False
    
    
    if arith:
        n=2*arr[n-1]-arr[n-2]
        return n
    elif geo:
        n=arr[n-1]**2/arr[n-2]
        return n
    elif checkIsFibonacci(arr,n):
        n = arr[n-1] + arr[n-2]
        return n
    else:
        return -999




n = int(input())
arr = list(map(int, input().split()))
print(solve(arr,n))