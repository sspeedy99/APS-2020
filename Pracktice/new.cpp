/* Author - sspeedy99
Editorial - Simple Solution
The solution is pretty straight forward. We only have to find the shortest path between 1 to n in the given undricted path. Simple BFS is enough, use a vector to print the path */




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

vector<bool>vis;
vector<vector<int>>graph;
vector<ll>parent;
ll n,m;

void bfs(int src){
    queue<ll>q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(auto it: graph[u]){
            if(!vis[it]){
                q.push(it);
                vis[it] = true;
                parent[it] = u;
            }
        }
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
    ll src, dest;
    graph.resize(n+1);
    vis.resize(n+1);
    parent.resize(n+1);
    for(int i=0; i<=n; i++) parent[i] = -1;
    for(int i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    cin>>src>>dest;
    bfs(src);
    stack<ll>s;
    while(dest != -1){
        s.push(dest);
        dest = parent[dest];
    }
    cout<<(sz(s)-2)<<endl;
    
    return 0;
}