t=int(input())

def solve(inp,n,a):

for i in range(t):
    a=[0 for i in range(31)]
        n,q=map(int,input().split())
        l=list(map(int,input().split()))
        for i in range(n):
            for j in range(31):
                x=1<<j
                if l[i]&x:
                    a[j]+=1
        ans=0
        for i in range(31):
            x=1<<i
            if a[i]:
                ans+=x
        print(ans)
        for k in range(q):
            idx,val=map(int,input().split())
            for i in range(31):
                x=1<<i
                if l[idx-1]&x:
                    a[i]-=1
            for i in range(31):
                x=1<<i
                if val&x:
                    a[i]+=1
            l[idx-1]=val
            ans=0
            for i in range(31):
                x=1<<i
                if a[i]>0:
                    ans+=x
        print(ans)