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

int getLargeNodeCount(treenode<int>* root, int x){
    if(root==NULL){
        return 0;
    }
    int ans = 0;
    if(root->data>x){
        ans++;
    }

    for(int i=0;i<root->children.size();i++){
        int small = getLargeNodeCount(root->children[i],x);
        ans += small;
    }
    return ans;
}