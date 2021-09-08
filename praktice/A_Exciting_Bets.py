for _ in range(int(input())):
    a,b = map(int,input().split())
    if a == b:
        g = 0
        stps = 0
    else:
        g = abs(a-b)
        stps = min(a%g,(g-a)%g)
    print(g,stps)