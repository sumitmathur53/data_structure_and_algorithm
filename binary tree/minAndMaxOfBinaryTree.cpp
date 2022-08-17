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

pair<int,int> minAndMax(Binarytree<int>* root){

    if(root == NULL){
        pair<int,int> p;
        p.first = 2142122;
        p.second = -999399;
        return p;
    }

    pair<int,int> leftAns = minAndMax(root->left);
    pair<int,int> rightAns = minAndMax(root->right);

    int lmax = leftAns.second;
    int rmax = rightAns.second;

    int lmin = leftAns.first;
    int rmin = rightAns.first;

    int maximum = max(lmax,max(root->data, rmax));
    int minimun = min(lmin,min(root->data,rmin));

    pair<int,int> p;
    p.first = minimun;
    p.second = maximum;
    return p;
}