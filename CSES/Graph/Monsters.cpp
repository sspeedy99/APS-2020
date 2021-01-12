/* Author - sspeedy99
Editorial - Simple Solution
This is the one of the toughest problem in the  graph section, you can use multisource BFS to solve this time of probwma*/

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

int n,m;
vector<pair<int,int>>monsters; // to store grid cordianetes of all the monsters 
vector<vector<int,int>>graph; // time taken by the monster to reach the the location (x,y)
map<pair<int,int>,pair<int,int>> parent_map; // mapping parent of each point in the grid 
pair<int,int> si, se; // starting and the ending positions
vector<pair<int, int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};

//helper function - to check if a particular cell is not out of bounds -- timer is used to track current time.
bool isValid(int x, int y, int timer){
    if(x < 0 || x>=n || y< 0 || y >= m ) return false;
    if (graph[x][y] <= timer) return false;
    return true;
}

//helper function to find weather the given cordinate is the required exit
bool isExit(int x, int y, int timer){
    if(!isValid(x,y,timer)) return false;
    if(x == 0 || y == 0 || x == n-1 || y == m-1) return true;
    return false;
}

bool bfs_escape(){
    queue<pair<pair<int,int>, int>> q;
    q.push(mp(si,0));
    parent_map[si] = {-1,-1}; // parent of the starting node is -1,-1
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;
        timer++; q.pop();
        for(auto mv: moves){
            int tx = cx+mv.first;
            int ty = cy+mv.second;
            if(isExit(tx,ty,timer)){
                parent_map[{tx,ty}] = {cx,cy};
                se = {tx,ty};
                return true;
            }
            if(isValid(tx,ty,timer)){
                parent_map[{tx,ty}] = {cx,cy};
                graph[tx][ty] = timer;
                q.push({{tx,ty},timer});
            }
        }
    }
    return false;
}

//helper code - multi source bfs for each monsters
void preprocess(){
    queue<pair<pair<int,int>,int>>q;
    for(auto m: monsters)
        q.push(mp(m,0));
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;
        timer++;q.pop();
        for(auto mv: moves){
            int tx = cx+mv.first;
            int ty = cy+mv.second;
            if(isValid(tx,ty,timer)){
                q.push({{tx,ty},timer});
                graph[tx][ty] = timer;
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
    cin >> n >> m;
    graph.resize(n);
    for(int i = 0; i < n; ++i)
    {
        graph[i].resize(m);
    }
    
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
        graph[i][j] = INT_MAX; // time taken to reach node i,j at t = 0 will infinite
        }
    }  
    
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
        char c; cin >> c;
        if(c == '#')
        {
            graph[i][j] = 0;
        }
        else if(c == 'M')
        {
            graph[i][j] = 0;
    
            monsters.push_back({i,j});
        }
        else if(c == 'A')
        {
            graph[i][j] = 0;
            si = {i,j};
        }
        else
        {
            graph[i][j] = INT_MAX;
        }
        }
    }
    if(si.first == 0 or si.second == 0 or si.first == n-1 or si.second == m-1) 
    {
        cout << "YES" << endl;
        cout << 0;
        return 0;
    }
    preprocess();
    
    if(!bfs_escape())
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    pair<int,int> tmp = se;
    pair<int,int> tmp1 = parent_map[se];
    pair<int,int> ed = {-1,-1}; 
    vector<char> ans;
    while(tmp1 != ed)
    {
    
        if((tmp.second - tmp1.second) == 1 and (tmp.first - tmp1.first) == 0)
        {
        ans.push_back('R');
        }
        if((tmp.second - tmp1.second) == -1 and (tmp.first - tmp1.first) == 0)
        {
        ans.push_back('L');
        }
        if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == 1)
        {
        ans.push_back('D');
        }
        if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == -1)
        {
        ans.push_back('U');
        }
        tmp = parent_map[tmp];
        tmp1 = parent_map[tmp];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto c: ans)
    {
        cout << c;
    }
    
}

