for _ in range(int(input())):
	n = int(input())
	A = list(map(int,input().split()))
	B = list(map(int,input().split()))
	flag = 1
	alpha,beta = max(A), max(B)
	if alpha > beta :
		for i in B:
			if alpha < i:
				flag = 0
				break;
	elif alpha < beta:
		for i in A:
			if beta < i:
				flag = 0
				break;

	else:
		flag = 0

	if flag == 1:
		print("YES")
	else:
		print("NO")
