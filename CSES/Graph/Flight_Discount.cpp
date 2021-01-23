/* Author - sspeedy99
Editorial - Simple Solution
This problem is based on the modifications on dijikstra's algorithm */




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


vector<vector<pair<int,int>>>g; // std implementation of weighted directed graph
vector<int>disc;
vector<int>dist;
int n,m;

void solve(){
    //min heap implementation of the priority queue
    priority_queue< 
	pair<int, pair<int,int>>, 
	vector<pair<int, pair<int,int>>>,
	greater<pair<int, pair<int,int>>>
	> pq;
    for(int i=2; i<=n; i++){
        disc[i] = INF;
        dist[i] = INF;
    }
    pq.push({0,{1,0}});
    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second.first;
        int f = pq.top().second.second;
        pq.pop();
        if(f == 1)
			if(disc[u] < d) continue; 
 
		if(f == 0)
			if(dist[u] < d) continue; 
 
        for(auto e : g[u]){
            int v = e.first;
            int c = e.second;
			if(f == 0) 
			{
				if(dist[v] > c + d) 
				{
					dist[v] = c+d;
					pq.push({dist[v], {v,0}});
				}
				if(disc[v] > d + c/2) 
				{
					disc[v] = d + c/2;
					pq.push({disc[v], {v,1}});	
				}
			}
 
			if(f==1)
			{
				if(disc[v] > d + c)
				{
					disc[v] = d + c;
					pq.push({disc[v], {v,1}});	
				}
			}
 
		}
	}
 
	cout << disc[n] << endl;

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
    g.resize(n+1);
    disc.resize(n+1);
    dist.resize(n+1);
    for(int i=0; i<m; i++){
        int u,v,c;
        cin>>u>>v>>c;
        g[u].pb({v,c});
    }   
    solve();
    
    return 0;
}