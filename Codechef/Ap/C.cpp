#include <bits/stdc++.h>
using namespace std;
using vi = vector <int> ;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define trace(x)  for (auto itr : x)
#define rep(i, n) for (auto i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)


const ll N = 1e5+8;

int solve(int n, int k) 
{ 
    vi P;  
    while (n%2 == 0) 
    { 
        P.pb(2); 
        n /= 2; 
    } 
    for (int i=3; i*i<=n; i=i+2) 
    { 
        while (n%i == 0) 
        { 
            n = n/i; 
            P.pb(i); 
        } 
    } 

    if (n > 2) 
        P.pb(n); 

    if (sz(P) < k) 
    {  
        return 0; 
    } 

    return 1;

} 



int32_t main()
{
	IOS;
    int q,x,k;
    cin>>q;
    while(q--){
        cin>>x>>k;
        cout<<solve(x,k)<<endl;
    }

	return 0;
}


 

 
