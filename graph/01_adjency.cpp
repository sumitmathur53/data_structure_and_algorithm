#include<bits/stdc++.h>
using namespace std;


int main(){

    int v,e; // here v is no of nodes and e number of edges
    cin>>v>>e;
    // creating 2d array 
    // inilialising the 2d vector with zero;
    vector<vector<int>> adj(v+1 , vector<int>(v+1,0));

    for(int i=0;i<e;i++){
        // taking the input for edges between node
        int x,y;
        cin>>x>>y;

        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    for(int i=1; i<adj.size(); i++){

        for(int j=1; j<adj[i].size(); j++){

            cout<<adj[i][j]<<" ";

        }cout<<endl;
    }

    cout<<endl;

    for(int i=1;i<=v;i++){

        for(int j =1; j<=v ;j++){
            cout<<adj[i][j]<<" ";
        }cout<<endl;

    }
    
}