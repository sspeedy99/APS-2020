for _ in range(int(input())):
	n,m,k = map(int,input().split())
	ans = 0
	for i in range((k+2),(k+n+m+1)):
		ans = ans ^ i
	print(ans)