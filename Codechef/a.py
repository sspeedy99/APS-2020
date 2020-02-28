for _ in range(int(input())):
	n = int(input())
	sum = 0
	A = list(map(int, input().split()))
	B = list(map(int, input().split()))

	A = sorted(A)
	B = sorted(B)

	for i,j in zip(A,B):
		sum += min(i,j)

	print(sum)