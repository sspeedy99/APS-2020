/* Author - sspeedy99
Editorial - Simple Solution
Example of Djikstra's single source shortest path problem */




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
#define INF 1e17;
#define int long long int
 
 
const int N=1e6+5;
const int mod = 1e9+7;


int n,m;
vector< vector<pair<int,int>> > graph;
vector<int>dist;

void djikstra(){
    //priority queue implementation of min hep
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    repi(i,0,n) dist[i] = INF; //initialise all the distance as infinity
    pq.push({0,1}); // push the source in the priority queue;
    dist[1] = 0;
    //djikstra's algo
    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(dist[u] < d) continue;
        for(auto e: graph[u]){
            int v = e.first;
            int c = e.second;
            if(dist[v] <= c+d) continue;
            //edge relaxation d(to) = min(d(to),d(from)+edgeLen)
            else {
                dist[v] = c+d;
                pq.push({dist[v],v});
            }

        }
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
    graph.resize(n+1);
    dist.resize(n+1);
    for(int i=0; i<m; i++){
        int u,v,c;
        cin>>u>>v>>c;
        graph[u].pb({v,c});
    }

    djikstra();
    repi(i,1,n) cout<<dist[i]<<" ";

    return 0;
}