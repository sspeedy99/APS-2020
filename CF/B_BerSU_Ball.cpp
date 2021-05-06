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


#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define fi first
#define se second
#define sz(x) (int)((x).sizmedian = *prev(s.find_by_order(k/2));e())
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define trace(itr, x)  for (auto itr : x)
#define rep(i, n) for (auto i = 0; i < n; ++i)
#define repi(i, x, n) for (auto i = x; i <= n; ++i)
#define present(container, element) (container.find(element) != container.end())
#define notpresent(container, element) (container.find(element) == container.end())


const int N=1e5+5;

string s;

bool check(int k){
    int arr[4] = {0};
    for(int i=0; i<k-1; i++){
        int idx = s[i] - '0';
        arr[idx]++;
    }
    for(int i=k-1; i<s.size(); i++){
        if(arr[1] > 0 && arr[2] > 0 && arr[3] > 0) return true;
        int idx = s[i-k+1] - '0';
        arr[idx]--;
    }
    return false;
}

int main()
{
    // #ifndef ONLINE_JUDGE 
    // // For getting input from input.txt file 
    // freopen("input.txt", "r", stdin); 
  
    // // Printing the Output to output.txt file 
    // freopen("output.txt", "w", stdout); 
    IOS;
    int t; cin>>t;
    while(t--){
        cin>>s;
        int low = 3, high = s.size(), ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(check(mid)) ans = min(ans, mid),high = mid - 1;
            else low = mid + 1;
        }
        if (ans == INT_MAX) cout<<"0"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
