#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

 
const int N=1e5+5;
 
int32_t main()
{
	IOS;
	int n;
	cin>>n;
	int cost[n][n];

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>cost[i][j]; 
		}
	}

	int powi = pow(2,n);
	int dp[powi];
	memset(dp,INT_MAX,sizeof(dp));

	dp[0] = 0;

	int mask;
	for(mask =0;mask<powi;mask++) {
		int x = __builtin_popcount(mask);
		for(int j=0;j<n;j++) {
			if(mask&(1<<j)!=0)
				dp[mask|(1<<j)] = min(dp[mask|(1<<j)],dp[mask]+cost[x][j]);
		}
	}

	//cout<<dp[powi-1];

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cout<<cost[i][j]<<" "; 
		}
		cout<<endl;
	}

	return 0;
}

