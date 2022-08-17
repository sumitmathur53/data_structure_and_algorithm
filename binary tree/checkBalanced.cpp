#include<iostream>
using namespace std;


template<typename T>

class Binarytree{
    public:
    T data;
    Binarytree<T>* left;
    Binarytree<T>* right;

    Binarytree(T data){
        this->data=data;
        left = NULL;
        right = NULL;
    }

};

int height(Binarytree<int>* root){
    if(root==NULL){
        return 0;
    }

    return 1+height(root->left)+height(root->right);

}

bool checkBalaced(Binarytree<int>* root){
    if(root==NULL){
        return 1;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)<=1 && checkBalaced(root->left) && checkBalaced(root->right)){
        return 1;
    }

    return 0;

}

// this have time complexity o(n^2);

// we have to it in one function

pair<int,bool> isBalanced1(Binarytree<int>* root){

    if(root==NULL){
        pair<int,bool> p;
        p.first = 0;
        p.second = 1;
        return p;
    }

    pair<int,bool> lAns = isBalanced1(root->left);
    pair<int,bool> rAns = isBalanced1(root->right);

    bool ans;

    if((lAns.second!=1) || rAns.second!=1 || abs(lAns.first - rAns.first)>1){
        ans = false;
    }else{
        ans = true;
    }

    pair<int,bool> p;
    p.first = max(lAns.first,rAns.first)+1;
    p.second = ans;

    return p;

}

bool isBalanced(Binarytree<int> *root) {
	if(root==NULL){
        return 1;
    }
    
    return isBalanced1(root).second;
    
}