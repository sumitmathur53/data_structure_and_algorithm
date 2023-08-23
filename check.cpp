#include<iostream>
#include<bits/stdc++.h>
using namespace std;



void preparedlst(unordered_map<int,list<int>> &adj, vector<pair<int,int>> & edges){

    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


}

void bfs(unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visisted, vector<int> &ans, int node){

    queue<int> q;
    q.push(node);
    visisted[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto i : adj[frontNode]){
            if(!visisted[i]){
                q.push(i);
                visisted[i] = 1;
            }
        }
    }
}

vector<int> bfs(int vertex, vector<pair<int,int>> edges){

    unordered_map<int,list<int>> adj;
    vector<int> ans;
    unordered_map<int,bool> visited;

    preparedlst(adj,edges);
    
    // traversing all component 

    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(ad,visited,ans,i);
        }
    }
}


