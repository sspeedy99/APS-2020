/* Author - sspeedy99
Editorial - Simple Solution
The Number of rooms will be the number of connected componets in the grid. They can eaisly be found by applying dfs on the grid */




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
 
 
const int N=1e6+5;
const int mod = 1e9+7;

vector<bool> vis;
vector<vector<int>>graph;
vector<int>path;
int n,m;

void bfs(){
    queue<int>q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto it: graph[f]){
            if(!vis[it]){
                q.push(it);
                vis[it] = true;
                path[it] = f;
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
    graph.resize(n+1);
    vis.resize(n+1);
    path.resize(n+1);
    for(int i=0; i<=n; ++i)
        path[i] = -1;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int end = n;
    bfs();
    if(!vis[n]){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    stack<int>s;
    while(end != -1) {
        s.push(end);
        end = path[end];
    }
    cout<<sz(s)<<endl;
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}