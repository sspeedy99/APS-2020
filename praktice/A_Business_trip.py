k = int(input())
inp = list(map(int,input().split()))
inp.sort(reverse=True)
cnt = 0
flag = False
if k == 0:
    print("0")
else:
    sum = 0
    for i in inp:
        sum += i
        cnt += 1
        if sum >= k:
            flag = True
            break
    if flag == True:
        print(cnt)
    else:
        print(-1)


