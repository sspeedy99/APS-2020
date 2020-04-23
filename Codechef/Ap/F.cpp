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
    srand(time(0)); 
    int t,n,m,k;
    cin>>t;
    while(t--){
        int a,b;
        cin>>n>>m>>k;
        rep(i,n){
            cin>>a>>b;
        }
        
        for(int i=0; i<n; i++) {
            int num = (rand()%(m)) + 1; 
            cout<<num<<" ";
        }
        cout<<endl;
    }

	return 0;
} 
