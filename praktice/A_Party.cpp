
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
bool visited[2001];

vector<int>v[2001];
int c=1;
int d[2001];

void dfs(int x,int d)
{
	c = max(c,d);
	for(int i = 0; i < v[x].size(); i++)
	{

			dfs( v[x][i] ,d+1);

	}
}

int main()
{
	int t;
	memset(visited,false,sizeof visited);
	for(int i=0;i<2000;i++)d[i]=1;
	cin>>t;
	for(int i=0;i<2001;i++)
	{
		v[i].clear();
	}
	for(int i=1;i<=t;i++)
	{
		int x;
		cin>>x;
		if(x==-1)continue;
		v[x].push_back(i);
	}
	for(int i=1;i<=t;i++)
	{
		dfs(i,1);
	}
	cout<<c;
	
}