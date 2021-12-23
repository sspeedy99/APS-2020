for _ in range(int(input())):
    s = input()
    k = len(s)
    if k&1 :
        print("NO")
    else:
        j = (k//2)
        if(s[:j] == s[j:]):
            print("YES")
        else:
            print("NO")
