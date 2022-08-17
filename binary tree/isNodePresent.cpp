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

bool isNodepresent(binaryTreeNode<int>* root, int x){
    if(root == NULL){
        return false;
    }

    if(root->data == x){
        return true;
    }

    bool left1 = isNodepresent(root->left,x);
    if(left1){
        return true;
    }
    bool right1 = isNodepresent(root->right,x);
    if(right1){
        return true;
    }

}