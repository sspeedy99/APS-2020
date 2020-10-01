for _ in range(int(input())):
	x,y,z = map(int,input().split())
	mi = min(x,y,z)
	mx = max(x,y,z)
	if x<=y and y<=z:
		print("NO")

	else:
		print("YES")
		print(mi,mi,mx)
