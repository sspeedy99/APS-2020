#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

const int N=1e5+5;


int32_t main()
{
	IOS;
	int v,e,x,y;
	cin>>v;
	int edges[v+1][v+1] = {0};
	cin>>e;
	while(e--){
		cin>>x>>y;
		edges[x][y] = 1;
		edges[y][x] = 1;
	}

	for(int i=0; i<v; ++i)
		for(int j=0; j<v; ++j)
			cout<<edges[i][j]<<" ";
		cout<<endl;

	return 0;
}