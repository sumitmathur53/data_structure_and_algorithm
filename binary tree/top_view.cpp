#include<bits/stdc++.h>

using namespace std;


// we will use level order traversal 
// we need quueue and the map to store the value


// Create a function to print the top view of the binary tree
// If the root is equal to the null value then return from the function (Base case)
// Create a queue of type Node* and a map of type <int, int> and a variable hd to calculate the horizontal distance
// Set hd of the root equal to zero and push it into the queue
// Run a while loop till the queue is not empty
// set hd equal to root->hd
// Check if this hd already exists in the map, If not then set this node->val in map[hd]
// If root->left exists then set its hd = root->hd – 1 and push it into the queue
// If root->right exists then set its hd = root->hd + 1 and push it into the queue
// Pop the front element of the queue and set its value in the root
// Print the answer using the map

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

};

vector<int> topView(Node* root){
    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    map<int,int> m;

    queue<pair<Node*,int>> q;

    q.push({root,0});

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // maintain one to one maping
        //if one value is present for hd is present do nothing

        if(m.find(hd)==m.end()){  // it means if there is no value then add
            m[hd] = frontNode->data;
        }

        if(frontNode->left){

            q.push({frontNode->left,hd-1});
        }
        if(frontNode->right){
            q.push({frontNode->right,hd+1});
        }

        for(auto i:m){
            ans.push_back(i.second);
        }
    }
    
}