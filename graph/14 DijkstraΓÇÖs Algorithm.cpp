#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    

    // create adj list;

    unordered_map<int, list<pair<int,int>>> adj;

    for(int i=0; i<edges;i++){

        int u = vec[i][0];
        int v = vec[i][1];

        int w = vec[i][2]; // weight

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));

    }

    vector<int> dist(vertices);

    for(int i= 0 ; i<vertices ; i++){
        dist[i] = INT_MAX;
    }

    set<pair<int,int>> st; // make set distance , node

    dist[source] = 0;// aad the diatance in the dist vector

    // insetin the set
    st.insert(make_pair(0,source));


    while(!st.empty()){

        // feth top of the set

        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove the top node

        st.erase(st.begin());

        // traverse on the neighbour;

        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                //if there is record in set if it is the erase

                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));

                if(record != st.end()){
                    st.erase(record);
                }

                // distance update

                dist[neighbour.first] = nodeDistance+neighbour.second;

                // push the new record in the set

                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }

    }

    return dist;
}
