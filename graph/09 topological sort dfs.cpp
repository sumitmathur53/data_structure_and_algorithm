#include<bits/stdc++.h>
using namespace std;


void toposdfs(int node, unordered_map<int,bool> &visited,
 unordered_map<int, list<int>> &adj,stack<int> &s){


    visited[node] = 1;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            toposdfs(neighbour,visited,adj,s);
        }
    }

    s.push(node);

 }

vector<int> topologicalsort(vector<vector<int>> &edges, int v, int e){

    unordered_map<int, list<int>> adj;

    // topological sort is for the directed acyclic graph

    for(int i=0 ;i<e;i++){
        int x = edges[i][0];
        int y = edges[i][1];

        adj[x].push_back(y);
    }

    unordered_map<int,bool> visited;
    stack<int> s;

    // for all nodes

    for(int i=0;i<v;i++){
        if(!visited[i]){
            toposdfs(i,visited,adj,s);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
}