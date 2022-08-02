#include<iostream>
using namespace std;
#include<vector>

template<typename T>

class treenode{
    public:
    int data ;
    vector<treenode<T>*> children;

    treenode(T data){
        this->data = data;        
    }

    ~treenode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
};

// You are given a generic tree. You have to replace each 
//node with its depth value. You just have to update the 
//data of each node
void help(treenode<int>* root, int depth){
    root->data = depth;

    for(int i=0;i<root->children.size();i++){
        help(root->children[i], depth+1);
    }
}

void replace(treenode<int>* root){
    int depth = 0;
    help(root, depth);
}