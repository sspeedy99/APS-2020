// C++ program for activity selection problem 
// when input activities may not be sorted. 
#include <bits/stdc++.h> 
using namespace std; 

void SelectActivities(vector<int>s,vector<int>f){ 
// Vector to store results. 
	vector<pair<int,int>>ans; 

// Minimum Priority Queue to sort activities in ascending order of finishing time (f[i]). 

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p; 

	for(int i=0;i<s.size();i++){ 
		// Pushing elements in priority queue where the key is f[i] 
		p.push(make_pair(f[i],s[i])); 
	} 

	auto it = p.top(); 
	int cnt = 1;
	int start = it.second; 
	int end = it.first; 
	p.pop(); 
	ans.push_back(make_pair(start,end)); 

	while(!p.empty()){ 
		auto itr = p.top(); 
		p.pop(); 
		if(itr.second >= end){ 
			start = itr.second; 
			end = itr.first; 
			ans.push_back(make_pair(start,end)); 
			cnt++;
		} 
	} 
	cout << "Following Activities should be selected. " << endl << endl; 

	for(auto itr=ans.begin();itr!=ans.end();itr++){ 
		cout << "Activity started at: " << (*itr).first << " and ends at " << (*itr).second << endl; 
	} 
	cout<<"The Count is " << cnt<<endl;
} 

// Driver program 
int main() 
{ 
	vector<int>s = {3, 4, 5}; 
	vector<int>f = {5, 9, 8}; 
	SelectActivities(s,f); 

	return 0; 
} 
