for _ in range(int(input())):
    n,a,b = map(int, input().split())
    val = max(a,b)
    if (n<(val*2) + 1):
        print("-1")
    else:
        