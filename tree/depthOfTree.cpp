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

int leafNodes(treenode<int>* root){
    if(root==NULL){
        return 0;
    }
    int ans = 0;
    if(root->children.size()==0){
        ans++;
    }

    for(int i=0;i<root->children.size();i++){
        ans += leafNodes(root->children[i]);
    }

    return ans;
}

