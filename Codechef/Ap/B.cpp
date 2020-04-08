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



int32_t main()
{
	IOS;
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int temp, flag = 0;
        vi v(n+6, 0);
        rep(i,n) cin>>v[i];

        rep(i,n) {
            if(v[i] == 1) {
                if(v[i+1] == 0 && v[i+2] == 0 && v[i+3] == 0 && v[i+4] == 0 && v[i+5] == 0) flag = 1;
                else 
                    {
                        flag = 0;
                        break;
                    }
            }

        }

        (flag)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }

	return 0;
} 
