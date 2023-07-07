#include<bits/stdc++.h>
using namespace std;


int main(){

    int v,e;
    cin>>v>>e;

    vector<int> adj[10000];  // list of big size

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1;i<v+1;i++){
        cout<<i<<" -> ";

        vector<int> :: iterator it;

        for(it=adj[i].begin() ; it!=adj[i].end(); it++){

            cout<<*it<<" ";

        }cout<<endl;
    }



}