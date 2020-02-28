# The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence 
# such that all elements of the subsequence are sorted in increasing order.

def LIS(arr):
    n = len(arr)

    #dp array for storing the solution
    dp = [1 for i in range(n)]

    for i in range(1,n):
        for j in range(0,i):
            if arr[i] > arr[j] and (dp[j]+1) > dp[i]:
                dp[i] = dp[j] + 1
    
    return max(dp)


arr = [10, 22, 9, 33, 21, 50, 41, 60] 
print("The length of the longest increasing subsequence is ", LIS(arr))


