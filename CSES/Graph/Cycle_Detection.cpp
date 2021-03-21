/* Author - sspeedy99
Editorial - Cycle detection in an undirected Graph - Check if the given graph is a tree or not
Use the union-find algorithm. The idea is that for every edge, make subset from the vertices and if two vertices are in the same subset, then a cycle is found */




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

struct DSU {
	vector<int> e;
	void init (int n) { e = vector<int> (n, -1); }
	int get (int x) { return (e[x] < 0 ? x : e[x] = get(e[x])); }
	bool sameSet (int x, int y) { return get(x) == get(y); }
	int size (int x) { return -e[get(x)]; }
	bool unite (int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return 0;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return 1;
	}
}; 



int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    int n,m;
    cin>>n>>m;
    DSU d;
    d.init(n);
    int flag = 0;
    int u,v;
    while(m--){
        cin>>u>>v;
        if(!d.unite(u,v)){
            flag = 1;
            break;
        }
    }

    if(flag) cout<<"Cycle Detected"<<endl;
    else cout<<"No Cycle Found"<<endl;

    
    return 0;
}