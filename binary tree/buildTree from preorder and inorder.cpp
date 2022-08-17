#include<iostream>
using namespace std;

template<typename T>

class BinartTree{
    public:
    T data;
    BinartTree<T>* left;
    BinartTree<T>* right;

    BinartTree(int data){
        this->data = data;
        left = NULL;
        right = NULL; 
    }

    ~BinartTree(){
        delete left;
        delete right;
    }
};

int search(int inorder[], int start, int end, int curr){
    for(int i=start; i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

BinartTree<int>* buildTree(int preorder[], int inorder[], int start, int end){

    static int idx = 0;

    if(start>end){
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    BinartTree<int>* newnode = new BinartTree<int>(curr);

    if(start==end){
        return newnode;
    }

    int pos = search(inorder, start,end, curr);
    newnode->left = buildTree(preorder,inorder, start,pos-1);
    newnode->right = buildTree(preorder,inorder, pos+1, end);

    return newnode;
}

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

int search(int * inorder, int start, int end, int curr){
    for(int i=start; i<=end; i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}
BinaryTreeNode<int>* helper(int *preorder, int * inorder, int start, int end){
    static int idx = 0;
    
    if(start>end){
        return NULL;
    }
    
    int curr = preorder[idx];
    idx++;
    BinaryTreeNode<int>* newnode = new BinaryTreeNode<int>(curr);
    
    if(start==end){
        return newnode;
    }
    
    int pos = search(inorder,  start,  end,  curr);
    newnode->left = helper(preorder, inorder, start, pos-1);
    newnode->right = helper(preorder, inorder,pos+1,end);
    return newnode;
}


BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    int start = 0;
    int end = inLength-1;
    
    return helper(preorder, inorder, start, end);    
}