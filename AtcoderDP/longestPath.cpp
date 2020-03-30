// Longest Path in DAG //


#include <bits/stdc++.h>
using namespace std;
using vi = vector <int> ;
using ll = long long;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define fill(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define trace(x)  for (auto itr : x)
#define rep(i, n) for (auto i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)



const int N=1e5+5;


//dfs 
void dfs(int node, vi adj[], int dp[], bool vis[]) {
	vis[node] = true;
	for(int i=0; i<adj[node].size(); ++i) {
		if(!vis[adj[node][i]])
			dfs(adj[node][i], adj, dp,vis);
		//dp[i] - length of longest path starting from node i
		dp[node] = max(dp[node], 1+ dp[adj[node][i]]);
	}
}


int solve(vi adj[], int n) {
	int dp[n+1];
	bool vis[n+1];
	fill(dp,0);
	fill(vis,false);

	repi(i,1,n)
		if(!vis[i])
			dfs(i,adj,dp,vis); // call dfs for every unvisited vertix

	int ans = 0;
	for(int i=0; i<=n; i++)
		ans = max(ans,dp[i]);
	return ans;

}

int32_t main()
{
	IOS;
	int n,m,u,v;
	cin>>n>>m;
	vi adj[n+1];
	while(m--){
		cin>>u>>v;
		adj[u].pb(v);
	}

	cout<<solve(adj,n)<<endl;

	return 0;
}


 

 
