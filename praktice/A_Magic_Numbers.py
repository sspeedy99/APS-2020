str = input()
flag = True
for i in str:
    if i != '1' or i != '4':
        flag = False

if str[0] != '1':
    flag = False

if str.find("444") != -1:
    flag = False

if flag == True:
    print("YES")
else:
    print("NO")