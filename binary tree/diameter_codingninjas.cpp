#include<iostream>
using namespace std;

template<typename T>

class Binarytree{
    public:
    T root;
    Binarytree<T>* left;
    Binarytree<T>* right;

    Binarytree(T data){
        this->root=data;
        left = NULL;
        right = NULL;
    }

};

int height(Binarytree<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}

// timpcomplexity of height = 0(n)


int diameter(Binarytree<int>* root){
    if(root==NULL){
        return 0;
    }

    int option1 = height(root->left) + height(root->right) + 1;
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1,max(option2,option3));
}

// overall timecomplexity = 0(n^2)

pair<int , int> heightDiameter(Binarytree<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int ld = leftAns.first;
    int lh = leftAns.second;
    int rd = rightAns.first;
    int rh = rightAns.second;

    int height = 1+ max(lh,rh);
    int diameter = max(lh+rh+1 , max(ld,rd));  // in coding ninjas dia is lh+rh but it is lh+rh+1

    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
