#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>

class treenode{
    public:
    T data;
    vector<treenode<T>*> children;

    treenode(T data){
        this->data = data;
    }
};

int height(treenode<int>* root){
    if(root==NULL){
        return 0;
    }

    int ans = 0;

    for(int i=0;i<root->children.size();i++){
        int childHeight = height(root->children[i]);

        if(childHeight>ans){
            ans = childHeight;
        }
    }

    return ans+1;
}

void preorder(treenode<int>* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";

    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}

void postorder(treenode<int>* root){
    if(root==NULL){
        return;
    }

    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}