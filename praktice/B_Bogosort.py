for _ in range(int(input())):
    n = int(input())
    inp = sorted(list(map(int,input().split())), reverse=True)
    print(*inp, sep= " ")