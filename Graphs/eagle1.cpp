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

char a[60][60];
bool vis[60][60];
int n,m;

int solve(int i, int j){
    int msf = 0;
    if(i<=0 || i>n || j<=0 || j>m)return 0;
    for(int ii = -1; ii<=1; ii++){
        for(int jj = -1; jj<=1; jj++){
            if(ii == 0 && jj == 0) continue;
            if(a[i + ii][j + jj] == a[i][j]+1 && !vis[i + ii][j + jj]) // check if immediate neighbour is a consecutive character
            {
                vis[i + ii][j + jj]=true;
                msf=max(msf,solve(i + ii,j + jj));
            }
        }
    }
    return msf+1;
}
 
int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    // IOS;
    int idx = 1;
    while(1){
    cin>>n>>m;
    if(n==0&&m==0) break;
    if(n==0||m==0) {
        cout<<0<<endl;
        continue;
        }
    memset(a,'-',sizeof a);
    for(int i = 1;i<=n;i++)
    {
        char str[50];
        scanf("%s",str);
        for(int j=0;j<=m;j++)
        {
            a[i][j+1] = str[j];
        }   
    } // input taken

    fill(vis,false);
    int msf = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] == 'A'){
                vis[i][j] = true;
                msf = max(msf,solve(i,j));
            }
        }
    }

    cout<<"Case "<<idx<<": "<<msf<<endl;
    idx++;
    }



    return 0;
}