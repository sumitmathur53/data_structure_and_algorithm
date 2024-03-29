#include<iostream>
using namespace std;
#include<vector>

template<typename T>

class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};



vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){

    if(root==NULL){
        return NULL;
    }

    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftOutput = getRootToNodePath(root->left, data);

    if(leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRootToNodePath(root->right,data);

    if(rightOutput!=NULL){
         rightOutput->push_back(root->data);
         return rightOutput;
    }else{
        return NULL;
    }
}

vector<int>* pathBst(BinaryTreeNode<int>* root, int data){

    if(root==NULL){
        return NULL;
    }

    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    else if(data < root->data){
        vector<int>* output = pathBst(root->left,data);

        if(output!=NULL){
            output->push_back(root->data);
            return output;
        }
    }

    vector<int>* output = pathBst(root->right,data);

    if(output!=NULL){
        output->push_back(root->data);
    }
    return output;

}