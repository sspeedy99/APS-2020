for _ in range(int(input())):
    n,a,b,c,d = map(int, input().split())
    R = n * (a+b)
    L = n * (a-b)
    if R < (c-d) or (c+d) < L:
        print("No")
    else:
        print("Yes")