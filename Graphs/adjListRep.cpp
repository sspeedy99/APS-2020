#include <bits/stdc++.h>
using namespace std;

int main(){
    int Nodes = 5;
    int x,y;
    vector <vector<int>> Graph(5);
    for(int i=0; i<Nodes; ++i){
        cin>>x>>y;
        Graph[x].push_back(y);
    }
    
}