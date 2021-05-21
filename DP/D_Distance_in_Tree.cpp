/* Codeforces - Distance in Tree 
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
 
 
const int N=1e5+5;
const int mod = 1e9+7;
const ll inf = 1e18;

long long dp1[50005][505]; // dp1[i][j] = number of path of lenght j in a subtree rooted at i
long long dp2[50005][505]; // dp2[i][j] = number of path of length j in the subtree not rooted at i
vector<vector<long long>>edge;

//finds the number of path of every node as a root - calculate dp1[i][k] = number of path of lenght k in a subtree rooted at i
void dfs(int src, int parent, int k){
    for(auto child: edge[src])
        if(child != parent)
            dfs(child,src,k);

    dp1[src][0] = 1;
    for(int dist = 1; dist<=k; dist++){
        dp1[src][dist] = 0;
        for(auto child: edge[src]){
            if(child != parent)
                //state transition - see notes
                dp1[src][dist] += dp1[child][dist-1];
        }
    }
}

//finds the number of paths where path passes root - calculate dp2[i][k] = number of path of lenght k in a subtree not rooted at i
void solve(int src, int parent, int k){
    for(int dist = 0; dist<=k; dist++)
        dp2[src][dist] = dp1[src][dist];

    if(parent != 0) {
        dp2[src][1] += dp2[parent][0];
        for(int dist = 2; dist<=k; dist++){
            //state transitios - see notes
            dp2[src][dist] += dp2[parent][dist-1];
            dp2[src][dist] -= dp1[src][dist-2];
        }
    }

    for(auto child: edge[src])
        if(child != parent)
            solve(child,src,k);
}


int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    ll n, k;
    cin>>n>>k;
    edge.resize(n+1);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1,0,k);
    solve(1,0,k);

    long long ans = 0;
    for(int i = 1; i<=n; i++)
        ans += dp2[i][k];

    cout<<ans/2<<endl;

    return 0;
}