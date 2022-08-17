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

BinaryTreeNode<int>* helper(int * input, int start, int end){
    if(start>end){
        return NULL;
    }
    
    int mid = (start+end)/2;
    BinaryTreeNode<int>* newnode = new BinaryTreeNode<int>(input[mid]);
    
    newnode->left = helper(input,start,mid-1);
    newnode->right = helper(input,mid+1,end);
    
    return newnode;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    
     int start = 0;
     int end = n-1;
    
    return helper(input,start,end);
    
}