for _ in range(int(input())):
	n = int(input())
	arr = list(map(int,input().split()))
	arr.sort()
	if(len(set(arr)) == 1):
		print(0)
	else:
		if n&1 :
			mid = (n-1)//2
		else:
			mid = n//2
		ans = abs(arr[0]-arr[mid])+abs(arr[mid] - arr[n-1])+abs(arr[n-1]-arr[0])
		print(ans)