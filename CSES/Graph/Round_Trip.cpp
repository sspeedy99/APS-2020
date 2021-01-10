/* Author - sspeedy99
Editorial - Simple Solution
Cycle detection and cycle retrivel concept - A cycle is detected and retrived when we revisit a non parent neighbou */




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

 
 
const int N=1e6+5;
const int mod = 1e9+7;

vector<bool> vis;
vector<vector<int>>graph;
vector<int>parent;
int n,m,start_node, end_node;



bool dfs(int u, int p){
    vis[u] = true;
    parent[u] = p;
    for(auto v: graph[u]){
        if(v == p) continue;
        if(vis[v]){
            start_node = v;
            end_node = u;
            return true;
        }

        if(!vis[v])
            if(dfs(v,u))
                return true;
    }
    return false;
}

bool visit_all(){
    for(int i=1; i<=n; i++){
        if(!vis[i])
            if(dfs(i,-1))
                return true;
    }
    return false;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    cin>>n>>m;
    graph.resize(n+1);
    vis.resize(n+1);
    parent.resize(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int ans = visit_all();
    if(!ans){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    int tv = end_node;
    vi cycle;
    cycle.pb(end_node);
    while(tv != start_node){
        cycle.pb(parent[tv]);
        tv = parent[tv];
    }
    cycle.pb(end_node);
    cout<<sz(cycle)<<endl;
    show(cycle);
    
    return 0;
}