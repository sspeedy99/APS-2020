for _ in range(int(input())):
    n = int(input())
    print("NO") if n&(n-1) == 0 else print("YES")