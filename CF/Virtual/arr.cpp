#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define trace(x)  for (auto itr : x)
#define rep(i, n) for (auto i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)


const int N=1e5+5;

int32_t main()
{
    IOS;
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vi inp(n);
        vi op;
        rep(i,n) cin>>inp[i];
        int cnt = 0;
        op.pb(inp[0]);
        for(int i=1; i<n-1; ++i)
            if((inp[i-1] > inp[i] && inp[i] < inp[i+1]) || (inp[i-1] < inp[i] && inp[i] >inp[i+1])){
                op.pb(inp[i]);
            }
       op.pb(inp[n-1]);

       cout<<op.size()<<endl;
       for(int i=0; i<op.size(); ++i)
        cout<<op[i]<<" ";
        cout<<endl;

    }

    return 0;
}


 

 
    