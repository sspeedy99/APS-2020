/* Author - sspeedy99
Editorial - Simple Solution
Use the BFS on the grid to find the path between two points - note that, this is not a shortest path problem, hence simple bfs would be enough */


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

//path of each point in the grid
vector<vector<pair<int,int>>> path;
vector<vector<bool>> vis;
vector<pair<int, int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m,sx,sy,ex,ey;

//helper function - to check if a particular cell is not out of bounds
bool isValid(int x, int y){
    if(x < 0 || x>=n || y< 0 || y >= m ) return false;
    if (vis[x][y]) return false;
    return true;
}

//bfs on the grid
void bfs(){
    queue<pair<int,int>>q;
    q.push({sx,sy});
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(auto it: moves){
            int mvx = it.first;
            int mvy = it.second;
            if(isValid(cx+mvx, cy+mvy)){
                q.push({cx+mvx, cy+mvy});
                vis[cx+mvx][cy+mvy] = true;
                path[cx+mvx][cy+mvy] = {mvx,mvy};
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
    path.resize(n);
    for(int i=0; i<n; ++i) {
        path[i].resize(m);
        vis[i].resize(m);
    }

    
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            path[i][j] = {-1,-1};
            char c;
            cin>>c;
            if(c == '#') vis[i][j] = true;
            if(c == 'A'){
                sx = i;
                sy = j;
            }
            if(c == 'B') {
                ex = i;
                ey = j;
            }
        }
    }

    bfs();
    if(!vis[ex][ey]){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    vector<pair<int,int>>ans;
    pair<int,int> end = {ex,ey};

    while(end.first != sx || end.second != sy){
        ans.pb(path[end.first][end.second]);
        end.first -= ans.back().first;
        end.second -= ans.back().second;
    }

    reverse(all(ans));
    cout<<sz(ans)<<endl;
    for(auto c: ans){
        if(c.fi == 1 && c.se == 0) cout<<"D";
        else if(c.fi == -1 && c.se == 0) cout<<"U";
        else if(c.fi == 0 && c.se == 1) cout<<"R";
        else if(c.fi == 0 && c.se == -1) cout<<"L";
    }


    return 0;
}