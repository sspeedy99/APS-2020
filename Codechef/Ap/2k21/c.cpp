
  
/* Author - sspeedy99
Editorial: Find the size of subtree
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
#define show(container) for(auto it: container) cout<<it<<" "
 
 
const int N=1e6+5;
const int mod = 1e9+7;
const ll mex = 2e5 + 5;

vector<priority_queue<pair<ll,ll> > >ds;
vector<vector<ll>>children;
vector<ll>vals;
vector<ll>depth;
vector<ll>height; 
vector<bool>vis;

void numberOfNodes(ll s, ll e)
{
    vector<ll>::iterator u;
    depth[s] = 1;
    for (u = children[s].begin(); u != children[s].end(); u++) {
          
        if (*u == e)
            continue;
        numberOfNodes(*u, s);
        depth[s] += depth[*u];
    }
}

void bfs(int u)
{
    queue<int> q;
  
    q.push(u);
    vis[u] = true;
    
    while (!q.empty()) {
  
        int f = q.front();
        q.pop();
        // Enqueue all adjacent of f and mark them visited 
        for (auto i = children[f].begin(); i != children[f].end(); i++) {
            if (!vis[*i]) {
                q.push(*i);
                vis[*i] = true;
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
    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        children.resize(n+1); depth.resize(n+1,0);vals.resize(n+1);height.resize(n+1);vis.resize(n+1);
        ds.resize(n+1);
        for(int i=1; i<n; i++){
            ll u,v;
            cin>>u>>v;
            children[u].pb(v);
        }
        numberOfNodes(1,-1);
        bfs(1);
        
        for(ll u =1; u<=n; u++){
            for(auto v: children[u]){
                ds[u].push({depth[v],v});
            }
        }
        
        // vals[1] = x;
        // for(ll i =1; i<=n; i++){
        //     if(ds[i].size() != 0){
        //         ll k = 1;
        //         while(!ds[i].empty()){
        //             vals[ds[i].top().second] = vals[i]*k;
        //             ds[i].pop();
        //             k++;
        //         }
        //     }
        // }
        
        // ll sum = 0LL;
        // for(ll i=1; i<=n; i++)
        //     sum = (sum%mod + vals[i]%mod)%mod;
        // cout<<sum<<endl;
        for(int i=0; i<=n; i++)
            cout<<height[i]<<" ";
        cout<<endl;
        
        ds.clear();
        children.clear();
        vals.clear();
        depth.clear();
    }

    return 0;
}
