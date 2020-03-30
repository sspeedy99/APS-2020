#include <bits/stdc++.h>
using namespace std;
using vi = vector <int> ;
using vii = vector <long long> ;

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

ll solve(ll W, vii wt, vii val, ll n ) {
	int i, w;
	ll dp[n+1][W+1];
	repi(i,0,n){
		repi(w,0,W){
			if (i==0 || w==0)
				dp[i][w] = 0;
			else if (wt[i-1] <= w) 
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]],  dp[i-1][w]); 
            else
                dp[i][w] = dp[i-1][w]; 
		}
	}

	return dp[n][W];
}

const int N=1e5+5;

int32_t main()
{
	IOS;
	ll n,W;
	ll x,y;
	cin>>n>>W;
	vii val(n), wt(n);
	rep(i,n){
		cin>>x>>y;
		wt[i] = x;
		val[i] = y;
	}

	cout<<solve(W,wt,val,n)<<endl;


	return 0;
}


 

 
