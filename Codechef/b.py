for _ in range(int(input())):
	X,R,M = map(int,input().split())
	R *= 60
	M *= 60
	if R<= X:
		N = R
	else:
		N = X + 2 * (R -X)
	print("YES") if N <= M else print("NO")