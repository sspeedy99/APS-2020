n = int(input())
arr = list(map(int, input().split()))
print(*sorted(arr), sep=" ")