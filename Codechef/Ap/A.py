for _ in range(int(input())):
	n = int(input())
	inp = list(map(int,input().split()))
	inp =sorted(inp,reverse=True)
	ans = 0
	MOD = 1000000007
	for i in range(len(inp)):
		if inp[i]-i < 0:
			inp[i] = 0
		else:
			inp[i]-=i
		ans += inp[i]

	print(ans%MOD)


