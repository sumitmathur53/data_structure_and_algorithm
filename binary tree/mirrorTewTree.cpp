#include<iostream>
using namespace std;
#include<queue>

template<typename T>

class binaryTreeNode{
    public:
    T data;
    binaryTreeNode<T>* left;
    binaryTreeNode<T>* right;

    binaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binaryTreeNode(){
        delete left;
        delete right;
    }
};

void mirror(binaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }

    binaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right); 
}