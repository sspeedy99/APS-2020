t=int(input())
for i in range(t):
    flag=0
    s=input()
    if s.find('MU')!=-1:
        flag=1
    else:
        for j in range(len(s)-2):
            if s[j+1]=='?' and s[j]=='M' and s[j+2]=='U':
                flag=1
                break
        
    if flag==1:
        print('Yes')
    else:
        print('No')