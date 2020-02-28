/*Consider a game where a player can score 3 or 5 or 10 points in a move. 
Given a total score n, find number of ways to reach the given score.*/

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

 
const int N=1e5+5;

int countWays(int n) {
	int dp[n+1];
	memset(dp,0,sizeof(dp));

	//base case
	dp[0] = 1;

	for(int i=3; i<=n; i++)
		dp[i] += dp[i-3];
	for(int i=5; i<=n; i++)
		dp[i] += dp[i-5];
	for(int i=10; i<=n; i++)
		dp[i] += dp[i-10];

	 return dp[n];
}
 
int32_t main()
{
	IOS;
	int n;
	cin>>n;
	cout<<countWays(n)<<endl;

	return 0;
}