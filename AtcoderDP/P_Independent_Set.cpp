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
 
 
const int N=1e5+5;
const int mod = 1e9+7;
const ll inf = 1e18;

int dp[N][2];
vector<vector<int>>edge;

void dfs(int src, int parent){
    //dp[v][0] - no of ways tree can be colored if the selected node is colored white
    //dp[v][1] - no of ways tree can be colored if the selected node is colored black
    dp[src][0] = dp[src][1] = 1;
    for(auto child : edge[src]){
        if(child == parent) continue;
        dfs(child,src);
        //if the current node is colored with white, the coloring of the child does not matter
        dp[src][0] = dp[src][0] * (dp[child][0] + dp[child][1]%mod)%mod;
        //if the current node is colored with black, the children can be only colored white
        dp[src][1] = dp[src][1] * dp[child][0] % mod;
    }
} 

int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    int n;
    cin>>n;
    edge.resize(n+1);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,-1);
    //answer will be no of ways the node can be colored either black and white
    cout<<(dp[1][0] + dp[1][1])%mod;
    return 0;
}