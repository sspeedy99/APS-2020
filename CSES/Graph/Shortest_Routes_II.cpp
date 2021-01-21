/* Author - sspeedy99
Editorial - Simple Solution
Example of Floyd-Warshall all pair shortest path */


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
#define int long long int
 
 
const int N=1e6+5;
const int mod = 1e9+7;
const int INF = 1e15;

//adjeceny matrix rep of the graph
vector<vector<int>> graph;

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    int n,m,q;
    cin>>n>>m>>q;
    graph.resize(n+1);
    for(int i=0; i<=n; ++i) graph[i].resize(n+1);
    for(int i=1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            graph[i][j] = graph[j][i] = INF;
        }
    }
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v] = graph[v][u] = min(graph[u][v],w);
    }

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);

    while(q--){
        int u,v;
        cin>>u>>v;
        (graph[u][v] == INF) ? cout<<"-1"<<endl : cout<<graph[u][v]<<endl; 
    }
    
    return 0;
}