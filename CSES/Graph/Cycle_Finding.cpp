/* Author - sspeedy99
Editorial - Simple Solution
Use the Bellman ford algorithm to find the negative cycle in the graph */




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
const int INF = 9e17;

struct edge {
    int a;
    int b;
    int cost;
};

vector<edge>g;
vector<int>dist;
vector<int>parent;
int n,m;

void negCycle(){
    int x;
    for(int i=1; i<=n; i++){
        x = -1;
        for(auto e: g){
            int u = e.a;
            int v = e.b;
            int c = e.cost;
            if(dist[u] + c < dist[v]){
                dist[v] = dist[u]+c;
                parent[v] = u;
                x = v;
            }
        }
    }
    if(x == -1) 
        cout<<"NO"<<endl;
    else {
        for(int i=1; i<=n; i++)
            x = parent[x];

        vi cycle;
        for(int v = x;;v=parent[v]){
            cycle.pb(v);
            if(v==x && cycle.size() > 1)
                break;
        }
        reverse(all(cycle));
        cout<<"YES"<<endl;
        show(cycle);

    }
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
    dist.resize(n+1);
    parent.resize(n+1);
    g.resize(m);
    for(int i=0; i<m; i++){
        struct edge input;
        cin>>input.a>>input.b>>input.cost;
        g[i] = input;
    }
    repi(i,1,n) parent[i] = -1;
    negCycle();
    return 0;
}