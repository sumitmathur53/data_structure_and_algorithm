#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<climits>

template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
};


bool isbst(BinaryTreeNode<int>* root, BinaryTreeNode<int>* min, BinaryTreeNode<int>* max){

    if(root==NULL){
        return true;
    }

    if(min!=NULL && root->data <= min->data){
        return false;
    }

    if(max!=NULL && root->data >= max->data){
        return false;
    }

    bool leftValid = isbst(root->left,min,root);
    bool rightValid = isbst(root->right,root,max);

    return leftValid and rightValid;
}

bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    BinaryTreeNode<int>* min = NULL;
    BinaryTreeNode<int>* max = NULL;
    
    return isbst(root,min,max);
}

bool helper(BinaryTreeNode<int>* root, int minima, int maxima){

    if(root==NULL){
        return true;
    }

    if(root->data < minima || root->data > maxima){
        return false;
    }

    bool leftAns = helper(root->left,minima,root->data);
    bool rightAns = helper(root->right,root->data,maxima);

    return leftAns and rightAns;
}

bool isBst(BinaryTreeNode<int>* root){
    return helper(root, INT_MIN, INT_MAX);
}