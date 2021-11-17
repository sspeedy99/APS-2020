for _ in range(int(input())):
    a,b,n,S = map(int,input().split())
    if S%n <= b and (a * n) + b >= S :
        print("YES")
    else:
        print("NO")