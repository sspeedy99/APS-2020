/* Author - sspeedy99
Editorial - Simple Solution
This is not an important question */



#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
using vi = vector<int>;
using vii = vector<long long>;
 
 
// Policy based data structure - order statistics tree with node update
typedef tree<int, null_type,
             less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;
 
 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define fill(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define trace(itr, x)  for (auto itr : x)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)
#define present(container, element) (container.find(element) != container.end())
#define notpresent(container, element) (container.find(element) == container.end())
#define show(container) for(auto it: container) cout<<it<<" "
 
 
vi adj[100005][2]; bool vis[100005];

void dfs(int v, int x) {
	vis[v] = true;
	for (int to : adj[v][x]) {
		if (!vis[to]) {
			dfs(to, x);
		}
	}
}

int main() {
    IOS;
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u][0].pb(v);
		adj[v][1].pb(u);
	}
	dfs(0, 0);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			cout << "NO" << '\n';
			cout << 1 << " " << i + 1 << '\n';
			return 0;
		}
	}
	memset(vis, false, sizeof(vis)); //fill vis with false
	dfs(0, 1);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			cout << "NO" << '\n';
			cout << i + 1 << " " << 1 << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
}