#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    int t;
    cin>>t;

    while(t--){
        vector<int> a(31,0);
        int n , q;
        cin>>n>>q;
        int arr[n];
        for(int i =0 ; i<n ; i++) cin>>arr[i];

        for(int i = 0 ; i<n ;i++){
            for(int j = 0 ; j<31 ; j++){
                int x = 1<<j;
                if(arr[i]&x) a[j]++;
            }
        }

        int ans = 0;
        for(int i = 0 ; i<31 ; i++){
            int x = 1<<i;
            if(a[i]) ans+=x;
        }
        cout<<ans<<"\n";

        for(int i = 0 ; i<q; i++){
            int ind , val ;
            cin>>ind>>val;

            for (int j ; j<31 ;j++){
                int x=1<<j;
                if(arr[ind-1]&x){
                    a[j]--;
                }
            }

            for (int j ; j<31 ;j++){
                int x=1<<j;
                if(val&x){
                    a[j]++;
                }
            }

            arr[ind-1] = val;

            ans = 0;
            for(int i = 0 ; i<31 ; i++){
                int x = 1<<i;
                if(a[i]) ans+=x;
            }
            cout<<ans<<"\n";

        }
    }

}