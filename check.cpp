#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
#include<string>
#include<queue>

#include<stack>

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

// level order treversal


void levelorder(Node* root){

    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* newnode = q.front();
        q.pop();

        if(newnode!=NULL){
            cout<<newnode->data<<" ";
            if(newnode->left){
                q.push(newnode->left);
            }
            if(newnode->right){
                q.push(newnode->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }

}

void printlevelsum(Node* root, int k){
    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    int level = 0;
    int sum=0;

    while(!q.empty()){
        Node* newnode = q.front();
        q.pop();
        if(newnode != NULL){
            if(level==k){
                sum += newnode->data;
            }
            if(newnode->left){
                q.push(newnode->left);
            }
            if(newnode->right){
                q.push(newnode->right);
            }
        }else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
}