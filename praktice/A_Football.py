str = input()
if (str.find("0000000") == -1):
    print("NO")
elif str.find("1111111") == -1:
    print("NO")
else:
    print("YES")