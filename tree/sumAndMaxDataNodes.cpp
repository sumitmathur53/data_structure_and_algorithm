#include<iostream>
#include<vector>
using namespace std;
#include<queue>

template<typename T>

class treenode{
    public:
    T data;
    vector<treenode<T>*> children;  // writing T is optional it by default assume it
    
    treenode(T data){
        this->data = data;
    }

};

int sumOfNodes(treenode<int>* root){
    int sum = 0;
    if(root==NULL){
        return sum;
    }
    sum = root->data;
    for(int i=0;i<root->children.size();i++){
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}

treenode<int>* maxDataNode(treenode<int>* root){

    if(root==NULL){
        return NULL;
    }

    int max = root->data;
    treenode<int>* current = root;

    for(int i=0;i<root->children.size();i++){

        treenode<int>* smallPart = maxDataNode(root->children[i]);

        if(smallPart->data > max){
            max = smallPart->data;
            current = smallPart;
        }

    }
    return current;
}