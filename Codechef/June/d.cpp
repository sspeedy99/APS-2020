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
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		ll ans, test, pow2 = 1;
		if(n == 1)
			cout<<"0"<<endl;

		else if(n&1){
			ans = (n-1)/2;
			cout<<ans<<endl;
		}

		else {
			test = n;
			while(test%2 == 0 && test >= 2){
				pow2*=2;
				test/=2;
			}

			ans = (n/(pow2*2));
			cout<<ans<<endl;
		}
		

	}


	return 0;
}


 

 
