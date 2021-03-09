/* Author - sspeedy99
Editorial - Classic problem of Kruskal's Algorithm */


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
int val;

struct Edge{
    int u;
    int v;
    int  weight;
    bool operator<(Edge const& other){
        return weight < other.weight;
    }
};

vector<int>parent;
vector<int>ranks;

//implementation of the union find algorithm
void make_set(int v){
    parent[v] = v;
    ranks[v] = 0;
}

int find_set(int v){
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
     a = find_set(a);
     b = find_set(b);

     if(a != b){
        if (ranks[a] < ranks[b])
            swap(a,b);
        parent[b] = a;
        if(ranks[a] == ranks[b])
            ranks[a]++;
     }
}

int n,m;
vector<Edge>edges;

//function to calculate the minimum cost of the spanning tree based on the kruskal's algorithm
int mst_cost(){
    int cost = 0;
    for(int i=1; i<=n; i++)
        make_set(i);
    sort(all(edges));
    for(Edge e: edges){
        if(find_set(e.u) != find_set(e.v)){
            cost += e.weight;
            union_sets(e.u,e.v);
            val--;
        }
    }
    return cost;
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
    edges.resize(n+1);
    parent.resize(n+1);
    ranks.resize(n+1);
    for(int i=0; i<m; i++){
        Edge inp;
        cin>>inp.u>>inp.v>>inp.weight;
        edges.push_back(inp);
    }
    val = n;

    (val != 1) ? cout<<mst_cost()<<endl : cout<<"IMPOSSIBLE"<<endl;
    return 0;
}