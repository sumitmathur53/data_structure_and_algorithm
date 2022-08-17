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

    ~binaryTreeNode{
        delete left;
        delete right;
    }
};

int count(binaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }

    return count(root->left)+count(root->right) + 1;
}

int height(binaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }

    return max(height(root->left), height(root->right))+1;
}