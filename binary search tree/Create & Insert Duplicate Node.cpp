#include<iostream>
using namespace std;
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

void insertDuplicateNode(BinaryTreeNode<int> *root){

    if(root==NULL){
        return;
    }

    BinaryTreeNode<int>* duplicate = new BinaryTreeNode<int>(root->data);
    duplicate->left = root->left;
    root->left = duplicate;

    insertDuplicateNode(duplicate->left);
    insertDuplicateNode(root->right);
}