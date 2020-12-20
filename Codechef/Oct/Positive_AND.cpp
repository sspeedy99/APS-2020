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

//find_by_order()->returns an iterator to the k-th largest element(0-based indexing)
//order_of_key()->Number of items that are strictly smaller than our item

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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
#define rep(i, n) for (auto i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)
#define present(container, element) (container.find(element) != container.end())
#define notpresent(container, element) (container.find(element) == container.end())


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
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n !=1 && n && !(n & (n - 1))) cout<<"-1"<<endl; // n is the perfect power of two
        else if(n==1) cout<<"1"<<endl;
        else if(n==3) cout<<"1 3 2"<<endl;
        else{
            vector<int> ans = {2,3,1};
            for(int i=5; i<=n; i++){
                if(!(i !=1 && n && !(i & (i - 1))))
                    if( (i-1) && !((i-1) & ((i-1) - 1))){
                        ans.pb(i);
                        ans.pb(i-1);
                }
                else ans.pb(i);
            }
            for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
            cout<<endl;
        }

    }
    return 0;
}


 