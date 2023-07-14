#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here

	unordered_map<int,list<int>> adj;

	for(int i=0;i<edges.size();i++){

		int x = edges[i].first;
		int y = edges[i].second;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	// bfs

	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;

	queue<int> q;
	q.push(s); // pushing sourrse node
	visited[s] = 1;
	parent[s] = -1;

	while(!q.empty()){

		int front = q.front();
		q.pop();

		for(auto i : adj[front]){
			if(!visited[i]){
				visited[i] = 1;
				parent[i] = front;
				q.push(i);
			}
		}
	}

	// prepare shortest path
	vector<int> ans;
	int currNode = t;
	ans.push_back(t);

	while(currNode!=s){
		currNode = parent[currNode];
		ans.push_back(currNode);
	}

	reverse(ans.begin(),ans.end());
	return ans;
	
}