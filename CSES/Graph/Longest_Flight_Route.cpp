/* Author - sspeedy99
Editorial - Simple Solution
Apply Dynamic programming on the topological sorting of the given graph */




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


int prev_flight[100000];
int dist[100000];
int in_degree[100000];
vector<int> edge[100000];
vector<int> backEdge[100000];

int N, M;

//Does a topological sort
void compute() {
	queue<int> q;
	for(int i = 0; i < N; i++) {
		if(in_degree[i] == 0) {
			q.push(i);
		}
	}

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		for(int next : edge[node]) {
			in_degree[next]--;
			if(in_degree[next] == 0) q.push(next);
		}

		//The below block computes the DP
		int mx = -999999999;
		int mx_node = -1;
		for(int prev : backEdge[node]) {
			if(dist[prev] + 1 > mx) {
				mx = dist[prev] + 1;
				mx_node = prev;
			}
		}

		dist[node] = mx;
		if(node == 0) dist[node] = 1;
		prev_flight[node] = mx_node;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for(int i = 0; i < N; i++) {
		prev_flight[i] = -1;
		dist[i] = -999999999;
		in_degree[i] = 0;
	}

	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		in_degree[b]++;
		edge[a].push_back(b);

		backEdge[b].push_back(a);
	}

	compute();

	stack<int> answer;
	int temp = N-1;

	bool contains0 = false;
	if(temp == 0) contains0 = true;

	while(temp != -1 && dist[temp] >= 0) {
		answer.push(temp);
		temp = prev_flight[temp];
		if(temp == 0) contains0 = true;
	}

	if(contains0) {
		cout << dist[N-1] << "\n";
		while(!answer.empty()) {
			cout << answer.top()+1;
			answer.pop();
			if(!answer.empty()) cout << " ";
		}
		cout << "\n";
	} else {
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}

