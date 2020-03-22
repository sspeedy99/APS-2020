#include <bits/stdc++.h>
#define int long long

using namespace std;

// Returns true if x is in range [low..high], else false 
inline bool inRange(unsigned low, unsigned high, unsigned x) 
{ 
	return ((x-low) <= (high-low)); 
}

int32_t main(){
    ios_base::sync_with_stdio(false); // some shit for faster io
    cin.tie(NULL);   // ditto
    cout.tie(NULL); // ditto

    int t;
    cin>>t;
    while(t--){
        int n , q;
        cin>>n>>q;
        int *arr =NULL;
        arr = new int[n+1];
        // int arr[n+1];
        arr[0] = 0;
        for(int i =1 ; i<=n ; i++)
            cin>>arr[i];
        while(q--){
            int left , right , y_pt , ct = 0 ;
            cin>>left>>right>>y_pt;
            for (int i = left ; i<right ; i++){
                // cout<<arr[i]<<"\t"<<y_pt<<"\t"<<arr[i+1]<<"\t"<<ct<<"\n";
                if ( inRange( min(arr[i],arr[i+1]) ,max(arr[i],arr[i+1]) ,y_pt))
                    ++ct;
            }
            cout<<ct<<"\n";

        }
        
    }
}