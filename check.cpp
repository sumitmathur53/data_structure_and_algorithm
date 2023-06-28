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

void flatten(Node* root){

    if(root==NULL || (root->left && root->right==NULL)){
        return;
    }

    if(root->left!=NULL){
        flatten(root->left);

        Node* temp = root->right;

        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;

        while(t->right!=NULL){
            t = t->right;
        }

        t->right = temp;
    }

    flatten(root->right);
}

Node* lca(Node* root, int n1, int n2){

    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node* leftlcs = lca(root->left,n1,n2);
    Node* rightlca = lca(root->right,n1,n2);

    if(leftlcs !=NULL && rightlca !=NULL){
        return root;
    }
    if(leftlcs!=NULL){
        return leftlcs;
    }
    return rightlca;
}
int finddistance(Node* root, int n1, int dist){

    if(root->data == n1){
        return dist;
    }

    int left = finddistance(root->left,n1,dist+1);


}
int disatance(Node* root,int n1, int n2){

    if(root==NULL){
        return 0;
    }

    int d1 = finddistance(root,n1,0);
    int d2 = finddistance(root,n2,0);

    return d1+d2;

}

void flatten(Node* root){

    if(root==NULL ||(root->left == NULL && root->right==NULL)){
        return;
    }

    if(root->left!=NULL){

        flatten(root->left);

        Node* temp = root->right;

        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while(t->right!=NULL){
            r = t->right;
        }
        t->right = temp;
    }

    flatten(root->right);
}