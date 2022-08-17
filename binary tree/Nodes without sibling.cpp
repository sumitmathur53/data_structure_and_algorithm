#include<iostream>
using namespace std;
#include<stack>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

void printNodesWithoutSibling(BinaryTreeNode<int> *root){

    if(root==NULL){
        return;
    }

    if(root->left != NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    else if(root->left == NULL && root->right!=NULL){
        cout<<root->data<<" ";
    }

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}