/* Author - sspeedy99
Editorial - Simple Solution
The Sloution requires Kahn's algorithm to solve the topological sort order in the graph */




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

vector<int>indegree;
vector<vector<int>>graph;
vector<int>top_order;
int n,m;

void topoSort(){
    for(int i=1; i<=n; i++)
        for(auto u: graph[i])
            indegree[u]++;
        
    
    int cnt = 0;
    queue<int>q;
    for(int i=1; i<=n; i++)
        if(indegree[i] == 0)
            q.push(i);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        top_order.pb(u);
        for(auto it: graph[u])
            if(--indegree[it] == 0)
                q.push(it);
        
        cnt++;

    }
    if(cnt != n) cout<<"IMPOSSIBLE"<<endl;
    else
        show(top_order);
    
    
}


int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    cin>>n>>m;
    graph.resize(n+1);
    indegree.resize(n+1,0);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
    }

    topoSort();

    
    return 0;
}