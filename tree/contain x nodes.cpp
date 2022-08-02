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

bool ispresent(treenode<int>* root, int x){
    if(root==NULL){
        return false;
    }

    if(root->data == x){
        return true;
    }

    bool ans = false;

    for(int i=0;i<root->children.size();i++){
        bool small = ispresent(root->children[i],x);

        if(ans!=small && small==true){
            ans = small;
        }

    }
    return ans;
}