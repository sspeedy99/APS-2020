/* CSES - Tree Matching
    One of the most important question - DP on trees
*/

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
 
 
const int N=2e5+5;
const int mod = 1e9+7;
const ll inf = 1e18;

long long dp[N][2]; 
vector<vector<long long>>edge;

void dfs(int src, int parent){
    for(auto child: edge[src]){
        if(child != parent){
            dfs(child,src);
            dp[src][0] += max(dp[child][0],dp[child][1]);
        }
    }
    for(auto child: edge[src])
        if(child != parent)
            dp[src][1] = max(dp[src][1],(dp[child][0] + 1 + dp[src][0] - max(dp[child][0],dp[child][1])));
    
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    ll n;
    cin>>n;
    edge.resize(n+1);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,-1);
    cout<<max(dp[1][0],dp[1][1])<<endl;
    return 0;
}