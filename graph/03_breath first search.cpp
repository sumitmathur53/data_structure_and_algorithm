#include<bits/stdc++.h>
using namespace std;


// int main(){

//     const int N = 1e5+2;

//     vector<int> adj[N];

//     bool visited[N]; // visited array

//     for(int i=0;i<N;i++){
//         visited[i] = 0;  // inisially marked zero
//     }

//     int v, e; // no. of vertex and no of edges
//     cin>>v>>e;

//     int x,y;  // inpusting edges
//     for(int i=0;i<e;i++){
//         cin>>x>>y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }

//     queue<int> q;

//     q.push(1); // we are starting from one
//     visited[1] = true;


//     while(!q.empty()){

//         int node = q.front();
//         q.pop();
//         cout<<node<<endl;

//         vector<int> :: iterator it;

//         for(it = adj[node].begin() ; it!= adj[node].end() ; it++){

//             if(!visited[*it]){
//                 visited[*it] = 1;
//                 q.push(*it);
//             }
//         }
//     }


// }


void prepareAdjList(unordered_map<int,list<int>> &adj,
vector<pair<int, int>> &edges ){

    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,
vector<int> &ans,int node){

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        // store front node in ans

        ans.push_back(frontNode);

        // traverse all neighbour 

        for(auto i : adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

void printadj(unordered_map<int,list<int>> &adj){
    for(auto i : adj){
        cout<<i.first<<"-> ";
        for(auto j: i.second){
            cout<<j<<" , ";
        }
        cout<<endl;
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here

    unordered_map<int,list<int>> adj;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepareAdjList(adj,edges);

    printadj(adj);

    // traaverse all component of a graph

    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
    }

    return ans;
}