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

vector<vector<bool>> vis;
vector<pair<int, int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m,res;

//helper function - to check if a particular cell is not out of bounds
bool isValid(int x, int y){
    if(x < 0 || x>=n || y< 0 || y >= m ) return false;
    if (vis[x][y]) return false;
    return true;
}

//dfs on the grid
void dfs(int x, int y){
	vis[x][y] = true;
	for(auto it: moves )
		if(isValid(x+it.first, y+it.second))
			dfs(x+it.first, y+it.second);
}

//number of connected componets in the grid
void connected_components(){
	for(int i=0; i<n; i++){
		for(int j =0; j<m; j++){
			if(!vis[i][j]){
				dfs(i,j);
				res++;
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
    vis.resize(n);
    for(int i=0; i<n; ++i)
        vis[i].resize(m);
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            char c;
            cin>>c;
            if(c == '#') vis[i][j] = true;
        }
    }

    connected_components();
    cout<<res<<endl;

    return 0;
}
