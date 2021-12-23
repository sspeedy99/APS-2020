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

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
 
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

void dfs(int u){
    vis[u] = true;
    for(auto it: graph[u])
        if(!vis[it])
            dfs(it);
}


int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        int cntMx = 0, cntMn = 0;
        cin>>n>>a>>b;
        int val = max(a,b);
        if(n < (2 * val) + 1){
            cout<<"-1"<<endl;
        }
        else{
            vi maxima, minima;
            for(int i = n; i>=0; i--){
                maxima.push_back(i);
                cntMx++;
                if(cntMx == a) break;
            }
            for(int i = 1; i<=n; i++){
                minima.push_back(i);
                cntMn++;
                if(cntMn == b) break;
            }
            for(int i)
            
        }
    }
    
    return 0;
}