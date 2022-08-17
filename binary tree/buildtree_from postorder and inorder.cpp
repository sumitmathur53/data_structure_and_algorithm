#include<iostream>
using namespace std;

template<typename T>

class BinaryTreeNode{
    public:
    T root;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data){
        this->root = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

int search(int inorder[], int start, int end, int curr){
    for(int i=start;i<=end;i++){

        if(inorder[i]==curr){
            return i;
        }

    }
    return -1;
}

BinaryTreeNode<int>* buildtree(int postorder[], int inorder[], int start, int end){

    static int idx = start-end+1; // size of inorder

    if(start>end){
        return NULL;
    }

    int curr = postorder[idx];
    idx--;

    BinaryTreeNode<int>* newnode = new BinaryTreeNode<int>(curr);

    if(start==end){
        return newnode;
    }

    int pos = search(inorder, start, end, curr);

    newnode->right = buildtree(postorder,inorder,pos+1,end);
    newnode->right = buildtree(postorder, inorder, start, pos-1);

    return newnode;

}