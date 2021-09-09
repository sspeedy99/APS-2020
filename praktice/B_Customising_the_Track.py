for _ in range(int(input())):
    n = int(input())
    x = sum(list(map(int, input().split())))%n
    print(x * (n - x))