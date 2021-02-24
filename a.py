for _ in range(int(input())):
	p,a,b,c = map(int,input().split())
	arr = [a,b,c]
	for i in range(len(arr)):
		t = p//arr[i]
		if(p%arr[i]):
			arr[i] = (t+1)*arr[i] - p;
		else:
			arr[i] = 0;
	print(min(arr))


