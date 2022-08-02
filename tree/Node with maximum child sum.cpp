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

treenode<int>* maxSumNode(treenode<int>* root){

    treenode<int>* ans = root;  

    int sum = root->data;
    for(int i=0;i<root->children.size();i++){ // sum of children for root node
        sum += root->children[i]->data;
    }

    for(int i=0;i<root->children.size();i++){

        treenode<int>* childmax = maxSumNode(root->children[i]); // get max node using recursion

        int smallsum = childmax->data;

        for(int i=0;i<childmax->children.size();i++){ // calculating for sum for max node
            smallsum += childmax->children[i]->data;
        }

        if(sum<=smallsum){  //comparision of result
            ans = childmax;
            sum = smallsum;
        }
    }
    return ans;
}