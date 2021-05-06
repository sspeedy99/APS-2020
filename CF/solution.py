
def isRepdigit(num) :
	prev = -1
	while (num) :
		digit = num % 10
		num //= 10
		if (prev != -1 and digit != prev) :
			return False
		prev = digit
	return True

# Driver code
for _ in range(int(input())):
    num = int(input())
    cnt = 0
    for i in range(1,num+1):
        if(isRepdigit(i)):
            cnt+=1
    print(cnt)


