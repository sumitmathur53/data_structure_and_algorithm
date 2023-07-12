#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};







class Solution {
public:

    Node* dfs(Node* curr , unordered_map<Node* , Node*> &mp){

        vector<Node*> neighbour; // creating list new one

        Node* clone = new Node(curr->val);  // clone the current
        mp[curr] = clone;   // put in map

        for(auto it : curr->neighbors){ // traversing the all neigbour of curr

            if(mp.find(it) != mp.end()){  // check if it is not map
                neighbour.push_back(mp[it]);
            }
            else{
                neighbour.push_back(dfs(it,mp));
            }            
        }

        clone -> neighbors = neighbour; // put the new adjacy list in curr one
        return clone;
    }


    Node* cloneGraph(Node* node) {

        unordered_map<Node* , Node*> mp;  // keep tracking the previous clone store address as ponter node

        if(node==NULL){
            return NULL;
        }

        if(node->neighbors.size()==0){

            Node* clone = new Node(node->val);
            return clone;
        }

        return dfs(node,mp);


    }
};