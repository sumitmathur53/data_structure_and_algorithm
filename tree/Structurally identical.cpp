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

bool areIdentical(treenode<int>* root1, treenode<int>* root2){
    if(root1->data != root2->data){
        return false;
    }

    if(root1->children.size() != root2->children.size()){
        return false;
    }

    bool ans = true;

    for(int i=0;i<root1->children.size();i++){
        bool small = areIdentical(root1->children[i],root2->children[i]);

        if(small != ans){
            ans = small;
        }
    }
    return ans;
}