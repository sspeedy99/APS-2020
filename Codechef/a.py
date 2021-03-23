def minSum(arr, n, k): 
	res = 0
	for i in range(k): 
		res += arr[i] 

	curr_sum = res 
	for i in range(k, n): 
		curr_sum += arr[i] - arr[i-k] 
		res = min(res, curr_sum) 

	return res 

def solve(sum,inp,n,k,cost):
	if sum == 0:
		return cost
	res = minSum(inp,n,k)
	


for _ in range(int(input())):
	n,k = map(int,input().split())
	inp = list(map(int,input().split()))
	total = sum(inp)
	