/* Important Tree Concept - LCA using Binary Lifting */

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
 
const int N=2e5+5;
const int mod = 1e9+7;
const ll inf = 1e18;

vector<int>edge[N];
int up[N][20];
int tin[N], tout[N];
int timer;

//using the binary lifting technique to calculate the 2^i th ancesor of a node
// tin and tout will be the entry time of a node- helps us to check if a node is ancestor of another node is constant time.
void dfs(int src, int parent){
    tin[src] = ++timer;
    up[src][0] = parent;
    for(int i=1; i<20; i++)
        up[src][i] = up[up[src][i-1]][i-1];
    
    for(auto child: edge[src])
        if(child != parent)
            dfs(child,src);
    tout[src] = ++timer;

}

//checking if the node is ancestor of another node in constant time
// if u is ancestor of v then u would be first to enter in dfs and last to exit from dfs compared to its descendets 
bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

//finding lca of two nodes
//check every node from the top as the ancestor of both u and v...if we find an ancestor to the v, lets say u..the first ancestor of u will be the lowest common ancestor to both u and v
int lca(int u, int v){
    if(is_ancestor(u,v)) return u;
    if (is_ancestor(v,u)) return v;
    for(int i =19; i>=0; i--)
        if(!is_ancestor(up[u][i],v)) // checking from the top of tree, every ancestor
            u = up[u][i];
    
    //the first ancestor will be the lca
    return up[u][0];
}


int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    int n,q;
    cin>>n>>q;
    for(int i=2; i<n+1; i++){
        int x; cin>>x;
        edge[x].push_back(i);
        edge[i].push_back(x);
    }
    dfs(1,1);
    while (q--) {
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
    
    return 0;
}