#include<bits/stdc++.h>
using namespace std;

void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int, list<int>> &adj,
vector<int> &component ){

    component.push_back(node);

    visited[node] = 1;

    // har connected tree k liye recursive call

    for(auto i :adj[node]){
        if(!visited[i]){
            dfs(i,visited,adj,component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here

    // prepare adj list

    unordered_map<int, list<int>> adj;

    for(int i=0;i<E;i++){
        int x = edges[i][0];
        int y = edges[i][1];

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<vector<int>> ans;

    unordered_map<int,bool> visited;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;  // component from dfs ans
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }

    }

    return ans;
}