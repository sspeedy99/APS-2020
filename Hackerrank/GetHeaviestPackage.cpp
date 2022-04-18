#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
    int mx=INT_MIN; int b[n];// taken another array for simplicity
    b[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){ // start traversing from the last.
        if(a[i]<b[i+1]){ // if condition is true then merge.
            b[i]=b[i+1]+a[i]; 
        }
        else 
           b[i]=a[i]; // otherwise ignore and copy same from given array.
        
    }
    for(int i=0;i<n;i++){
        mx=max(mx,b[i]); // find maximum from merged array.
    }
    cout<<endl;
    return mx;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve(a, n);
        cout << "\n";
    }
    return 0;
}
