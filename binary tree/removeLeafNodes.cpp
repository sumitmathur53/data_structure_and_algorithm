#include<iostream>
using namespace std;
#include<queue>

template<typename T>

class Binarytree{
    public:
    T data;
    Binarytree<T>* left;
    Binarytree<T>* right;

    Binarytree(T data){
        this->data=data;
        left = NULL;
        right = NULL;
    }

};

Binarytree<int>* removeLeafNodes(Binarytree<int>* root){
    if(root==NULL){
        return NULL;
    }

    if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
    }

    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);

    return root;
}