#include<iostream>
using namespace std;

template<typename T>

class Binarytree{
    public:
    T root;
    Binarytree<T>* left;
    Binarytree<T>* right;

    Binarytree(T data){
        this->root=data;
        left = NULL;
        right = NULL;
    }

};

int height(Binarytree<int>* root){
    if(root==NULL){
        return 0;
    }
    
    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight,rheight) + 1;
    
}


int diameter(Binarytree<int>* root){
    if(root == NULL){
        return 0;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);
    int currdia = lheight+rheight+1;

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(currdia , max(ldiameter,rdiameter));
}

