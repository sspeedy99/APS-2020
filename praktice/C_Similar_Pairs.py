for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    cntOdd, cntEven = 0 , 0
    for i in arr:
        if i&1:
            cntOdd += 1
        else:
            cntEven += 1

    if (((cntEven ^ cntOdd) & 1) != 0):
        print("NO")
    else:
        if cntEven%2 == 0 and cntOdd%2 == 0:
            print("YES")
        else:
            flag = 0
            for i in arr:
                for j in arr:
                    if abs(i-j) == 1:
                        flag = 1
                        break
            if flag:
                print("YES")
            else:
                print("NO")



