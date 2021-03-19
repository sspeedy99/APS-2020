/* Author - sspeedy99
Editorial - Strongly Connected Components in Directed Graph
In order to find strongly connected componets in directed graph, we Kosaraju's algorith - O(V+E) time complexcity*/




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
vector<vector<int>>graph,reverse_graph;
vector<int>order,component,tags;
int n,m,ids;


void dfs(int u){
    vis[u] = true;
    for(auto it: graph[u])
        if(!vis[it])
            dfs(it);
    order.pb(u);
}

void dfs2(int u){
    vis[u] = true;
    component.pb(u+1);
    tags[u] = ids;
    for(auto it: reverse_graph[u]){
        if(!vis[it])
            dfs2(it);
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
    cin>>n>>m;
    graph.resize(n);
    reverse_graph.resize(n);
    vis.resize(n,false);
    tags.resize(n,0);
    ids = 1;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        graph[u].pb(v);
        reverse_graph[v].pb(u);
    }

    for(int i=0; i<n; i++)
        if(!vis[i])
            dfs(i);
    
    vis.assign(n,false);
    for(int i=0;i<n;i++){
        int v = order[n-i-1];
        if(!vis[v]){
            dfs2(v);
            ids++;
            component.clear();
        }
            
    }
    cout<<ids-1<<endl;
    show(tags);
    cout<<endl;
    
    return 0;
}