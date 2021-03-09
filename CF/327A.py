from sys import maxsize

n = int(input())
a = list(map(int,input().split()))
b = []
start, end, s = 0,0,0
msf = -maxsize - 1
meh = 0
for i in range(len(a)):
	if a[i] == 0:
		b.append(1)
	else:
		b.append(-1)

	meh += b[i]
	if msf < meh:
		msf = meh
		start = s
		end = i
	if meh < 0:
		meh = 0
		s = i+1

for i in range(start,end+1):
	a[i] = 1-a[i]

print(a.count(1))
