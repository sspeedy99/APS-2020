for _ in range(int(input())):
    n = int(input())
    k = n - 2021
    if n<2020:
        print("NO")
    elif n%2020 ==0 or n%2021 == 0:
        print("YES")
    elif (k%2020 ==0 or k%2021 == 1):
        print("YES")
    else:
        print("NO")