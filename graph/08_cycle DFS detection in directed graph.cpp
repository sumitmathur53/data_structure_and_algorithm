#include<bits/stdc++.h>
using namespace std;

bool checkCycleDfs(int node, unordered_map<int,bool> &visited,
unordered_map<int,bool> &dfsvisited,unordered_map<int,list<int>> &adj){

  visited[node] = true;

  dfsvisited[node] = true;

  for(auto neighbour : adj[node]){

    if(!visited[neighbour]){
      bool cycleDetected = checkCycleDfs(neighbour,visited,dfsvisited,adj);

      if(cycleDetected){
        return true;
      }
    }
    else if (dfsvisited[neighbour]){
      // visited true;
      return true;
    }
  }

  dfsvisited[node] = false;
  return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  unordered_map<int,list<int>> adj;

  for(int i=0;i<edges.size();i++){

    int x = edges[i].first;
    int y = edges[i].second;

    adj[x].push_back(y);
  }

  // call dfs for all component

  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsvisited;

  for(int i=1;i<=n;i++){

    if(!visited[i]){
      bool cyclefound = checkCycleDfs(i, visited, dfsvisited, adj);

        if(cyclefound){
          return true;
        }    
    }
  }

  return false;
}