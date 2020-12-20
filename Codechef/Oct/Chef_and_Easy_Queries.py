for _ in range(int(input())):
    n, k = map(int,input().split())
    arr = list(map(int,input().split()))
    ans, temp = 0, 0
    flag = 0
    for i in range(n):
        if arr[i] >= k:
            temp += arr[i] -k
            arr[i] = k
        else:
            if(temp > 0):
                val = (k - arr[i])
                temp -= val
                arr[i] += val

    for i in range(n):
        if arr[i] < k:
            ans = i+1
            flag = 1
            break

    if(flag == 1):
        print(ans)
    else:
        ans = (n + temp//k + 1)
        print(ans)


    
