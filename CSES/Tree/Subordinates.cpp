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

vector<vector<int>>children; // to store the children of every node. children[parent_node] -> child_node1, child_node2
vector<int>subtree_size, depth; // subtree[node] -> size of subtree whose root is node, depth[node] -> depth of node 

//This function recursively calls the child of each node and add the size of the subtree of the child to the subtree size of the node.
void dfs_size(int node){
    subtree_size[node] = 1;
    for(auto child : children[node]){
        depth[child] = depth[node] + 1;
        dfs_size(child);
        subtree_size[node]+=subtree_size[child];
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
    int n;
    cin>>n;
    children.resize(n); subtree_size.resize(n); depth.resize(n);
    for(int i=1; i<n; i++){
        int parent;
        cin>>parent; parent--; // decrementing the parent to make the tree 0 based. 
        children[parent].pb(i);
    }
    dfs_size(0);
    
    for(auto i: subtree_size) cout<<i-1<<" ";
    return 0;
}