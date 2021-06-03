
/*
Binary Lifting - Kth ancestor of the node in O(logn) time.
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
 
const int N=2e5+5;
const int mod = 1e9+7;
const ll inf = 1e18;

vector<int>edge[N];
int up[N][20]; // up[i][j] = 2^j the ancestor of the node i, since we are jumping by power of 2, log of million is 20.

void binary_lifting(int src, int parent){
    up[src][0] = parent; //1st ancestor will be the parent of the node
    for(int i = 1; i<20; i++){
        if(up[src][i-1] != -1)
            up[src][i] = up[up[src][i-1]][i-1]; // ith parent of the src will be the i-1th parent of the parent. 
        else
            up[src][i] = -1;
    }
    //recurse for all the child in dfs manner
    for(auto child: edge[src]){
        if(child != parent)
            binary_lifting(child, src);
    }
}

int ans_query(int node, int jump){
    if(node == -1 || jump == 0)
        return node;
    for(int i=19; i>=0; i--){
        //if the jump is greater than 2^i
        if(jump >= (1<<i)){
            return  ans_query(up[node][i], jump - (1<<i));        
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
    int n,q;
    cin>>n>>q;
    for(int i=2; i<n+1; i++){
        int x; cin>>x;
        edge[x].push_back(i);
        edge[i].push_back(x);
    }
    binary_lifting(1,-1);
    while(q--){
        int node, k;
        cin>>node>>k;
        cout<<ans_query(node,k)<<endl;
    }
    return 0;
}
