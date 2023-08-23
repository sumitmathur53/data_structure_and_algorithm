#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent,vector<int> &disc, vector<int> &low, unordered_map<int,bool> &vis,
            unordered_map<int,list<int>> &adj,vector<int> &artiPoint,int &timer){

                vis[node] = 1;

                disc[node] = low[node] = timer++;

                int child = 0;

                for(auto nbr : adj[node]){

                    if(nbr==parent){
                        continue;
                    }
                    if(!vis[nbr]){
                        dfs(nbr,node,disc,low,vis,adj,artiPoint,timer);

                        low[node] = min(low[node],low[nbr]);
                        
                        // check articulation point

                        if(low[nbr] >= disc[node] && parent!=-1){
                            artiPoint[node] = true;
                        }
                        child++;

                    }
                    else{
                        low[node] = min(low[node],disc[nbr]); // backedge
                    }
                    
                }

                if(parent==-1 && child > 1){
                    artiPoint[node] = true;
                }


            }

int main(){
    int n = 5;
    int e = 5;

    vector<pair<int,int>> edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));


    unordered_map<int,list<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int,bool> vis;
    vector<int> artiPoint(n,0);
    int parent =-1;

    for(int i=0;i<n;i++){
        disc[i] = -1;
        low[i] = -1;
        vis[i] = false;
    }

    // dfs
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,disc,low,vis,adj,artiPoint,timer);
        }
    }

    // artipont print

    cout<<"aeticulation point -> "<<endl;

    for(int i=0;i<n;i++){
        if(artiPoint[i]!=0){
            cout<<i<<" ";
        }
    }


}