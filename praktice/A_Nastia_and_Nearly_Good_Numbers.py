for _ in range(int(input())):
    A,B = map(int,input().split())
    if B == 1:
        print("NO")
    else:
        print("YES")
        print(A, A*B, A*(B+1))