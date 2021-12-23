#include <iostream>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <climits>
#include <bits/stdc++.h>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define all(cont) cont.begin(), cont.end()
#define rep(i,s,n) for(ll i=s;i<n;i++)
#define repn(i,n,s) for(ll i=n-1;i>=s;i--)
#define print(arr,n) for(ll i=0;i<n;i++)cout<<arr[i]<<" ";
#define pi pair<int,int>
#define pb push_back
#define sorta(v) sort(v.begin(),v.end());
#define sortd(v) sort(v.begin(),v.end(),greater<int>());

bool cmp(pair<ll,pair<ll,ll>> p1,pair<ll,pair<ll,ll>> p2){
    return p1.second.first > p2.second.first;
}

bool cmp2(pair<ll,pair<ll,ll>> p1,pair<ll,pair<ll,ll>> p2){
    return p1.second.second > p2.second.second;
}

void dfs(ll curr,vector<bool>& visited,vector<ll> adj[]){
    visited[curr] = true;

    for(auto u:adj[curr]){
        if(!visited[u])
            dfs(u,visited,adj);
    }
}

void solve(){
    ll n;
    cin>>n;
    vector<pair<ll,pair<ll,ll>>> a(n);
    pair<ll,ll> mx = {INT_MIN,INT_MIN};
    rep(i,0,n) {
        a[i].first = i;
        cin>>a[i].second.first;

    }

    rep(i,0,n){
        cin>>a[i].second.second;
        if(a[i].second.first > mx.first || a[i].second.second > mx.first){
            mx.first = max(a[i].second.first,a[i].second.second);
            mx.second = i;
        }
    }

    sort(a.begin(),a.end(),cmp);

    vector<ll> adj[n+1];

    rep(i,1,n){
        adj[a[i].first].pb(a[i-1].first);
    }

    sort(a.begin(),a.end(),cmp2);

    rep(i,1,n){
        adj[a[i].first].pb(a[i-1].first);
    }

    vector<bool> visited(n);

    dfs(mx.second,visited,adj);

    for(auto u:visited){
        cout<<u;
    }
    cout<<endl;



}
  

int main() {
    FIO;
   
    int t;
    cin>>t;
      while(t--)
        solve();
    
    return 0;
}