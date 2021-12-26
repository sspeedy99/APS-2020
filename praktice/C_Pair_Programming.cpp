/* Author - sspeedy99
Editorial - Simple Solution
The solution is pretty straight forward. We only have to find the shortest path between 1 to n in the given undricted path. Simple BFS is enough, use a vector to print the path */




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

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
 
const int N=1e6+5;
const int mod = 1e9+7;




int main()
{
    // #ifndef ONLINE_JUDGE
    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
 
    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    IOS;
    int t;
    cin>>t;
    while(t--){
        int k,n,m;
        cin>>k>>n>>m;
        vi a(n),b(m);
        vi res;
        rep(i,n) cin>>a[i];
        rep(i,m) cin>>b[i];
        bool flag = true;
        int i =0, j = 0;
        while(i <n || j < m){
            if(i != n && a[i] == 0){
                res.push_back(0);
                k++;
                i++;
            }
            else if( j !=m && b[j] == 0){
                res.push_back(0);
                k++;
                j++;
            }
            else if(i != n && a[i] <= k)
                res.push_back(a[i++]);
            else if(j != m && b[j] <=k)
                res.push_back(b[j++]);
            
            else{
                
                cout<<"-1"<<endl;
                flag = false;
                break;
            }

        }

        if(flag){
            show(res);
            cout<<endl;
        }

    }

    
    return 0;
}