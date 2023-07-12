#include<bits/stdc++.h>
using namespace std;


bool isCyclicDfs(int node, int parent,unordered_map<int, list<int>> &adj,unordered_map<int ,bool> visited ){

    visited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected =  isCyclicDfs(neighbour,node,adj,visited); 
            if(cycleDetected){
                return true;
            }
        }
        else if(neighbour != parent){
            return true;
        }
    }
    return false;    
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    // create adjecy list

    unordered_map<int, list<int>> adj;

    for(int i=0; i<m;i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    //to handle disconnnected component

    unordered_map<int ,bool> visited;

    for(int i=0; i<n;i++){
        if(!visited[i]){
            bool ans = isCyclicDfs(i,-1,adj,visited);
            if(ans==1){
                return "Yes";
            }
        }
    }

    return "No";
}