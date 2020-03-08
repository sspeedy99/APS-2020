/* Find the number of connected components in a given graph using DFS */


#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

std::vector<int> adj[10];
bool visited[10];

//DFS Algorithm for adjecency list
void dfs(int s) {
	visited[s] = true;
	for(int i=0; i<adj[s].size(); ++i ) {
		if(visited[adj[s][i]] == false)
			dfs(adj[s][i]);
	}
}

 


const int N=1e5+5;
 
int32_t main()
{
	IOS;
	memset(visited,false,sizeof(visited));

	int nodes, edges, x, y, connected = 0;
	cin>>nodes;
	cin>>edges;

	for(int i=0; i<edges; ++i){
		cin >>x >> y;
		//Undirected Graph

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i=1; i<= nodes; ++i) {
		if(visited[i] == false) {
			dfs(i);
			connected++;
		}
	}

	cout<<"The Number of Connected components is "<< connected <<endl;

	return 0;
}