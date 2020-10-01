for _ in range(int(input())):
	n,k = map(int,input().split())
	inp = list(map(int,input().split()))
	inp = sorted(inp)
	mi = inp[0]
	ma = inp[n-1]
	cnt = 0
	for i in range(1,n):
		temp = k - inp[i]
		cnt += temp//mi

	print(cnt)
