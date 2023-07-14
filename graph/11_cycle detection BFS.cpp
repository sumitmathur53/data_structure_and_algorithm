#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  unordered_map<int,list<int>> adj;

  for(int i=0;i<edges.size();i++){

    int x = edges[i].first;
    int y = edges[i].second;

    adj[x].push_back(y);
  }

  // finding the indegree
  vector<int> indegree(n+1);

  for(auto i : adj){

    for(auto j : i.second){
      indegree[j]++;
    }
  }

  queue<int> q;

  for(int i=1;i<=n;i++){
    if(indegree[i]==0){
      q.push(i);
    }
  }

  int count = 0; // for valid topological sort if it equal to 
  // number of node then it is

  while(!q.empty()){
    int front = q.front();
    q.pop();

    count++;

    // neighbour indegree update

    for(auto neighbour :adj[front]){
      indegree[neighbour]--;
      if(indegree[neighbour]==0){
        q.push(neighbour);
      }
    }
  }

  if(count==n){
    return false;
  }else{
    return true;
  }
}