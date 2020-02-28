for _ in range(int(input())):
	inp= list(map(int, input().split()))
	n,k = inp[0], inp[1]

	inp = sum([int(x) for x in input().split()])
	print(inp%k)

