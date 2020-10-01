import math
for _ in range(int(input())):
	D,C = map(int,input().split())
	flag = 0
	while(C!=0):
		D -= C
		C = math.floor(C/2)
		if D <=0 :
			flag = 1
			break

	if flag == 1:
		print("1")
	else:
		print("0")

