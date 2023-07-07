#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
bool visited[N];
vector<int> adj[N];

void dfs(int node){

    // preorder
    visited[node] = true;
    cout<<node<<" ";

    // inorder

    vector<int> :: iterator it;

    // for(it = adj[node].begin() ; it!=adj[node].end(); it++){

    //     if(visited[*it]);
    //     else{
    //         dfs(*it);
    //     }
    // }

    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it);
        }
    }

    // postorder
    // cout<<node<<" ";
}


int main(){

    int n,e;
    cin>>n>>e;

    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }

    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        
        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    dfs(1);
}