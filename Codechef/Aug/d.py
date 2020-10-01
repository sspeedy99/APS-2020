from collections import Counter

for _ in range(int(input())):
	S = input()
	P = input()
	X = Counter(P)
	ans = []
	temp = []
	temp2 = []
	for i in S:
		if X[i] > 0:
			X[i] -=1
		else:
			ans.append(i)

	ans = sorted(ans)

	val = P[0]
	print(val)
	for i in ans:
		if i > val:
			# print(i)
			temp2.append(i)
		else:
			temp.append(i)

	print(temp)
	print("".join(temp)+P+"".join(temp2))
	# print(temp)
	# print(temp2)






