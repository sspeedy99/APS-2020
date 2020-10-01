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
	int t,n,k;
	cin>>t;
	while(t--){
		int sum =0,rev = 0;
		cin>>n>>k;
		vi inp(n);
		rep(i,n){
			cin>>inp[i];
			sum += inp[i];
		}
		rep(i,n){
			if (inp[i] > k)
				inp[i] = k;
			rev += inp[i];
		}

		cout<<(sum-rev)<<endl;
	}


	return 0;
}


 

 
