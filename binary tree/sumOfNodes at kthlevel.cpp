#include<iostream>
using namespace std;
#include<queue>

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

int sumAtK(Binarytree<int>* root, int k){
    if(root==NULL){
        return -1;
    }

    queue<Binarytree<int>*> q;
    q.push(root);
    q.push(NULL); // to get know anout level
    int level = 0;
    int sum = 0;

    while(!q.empty()){
        Binarytree<int>* newnode = q.front();
        q.pop();

        if(newnode!=NULL){
            if(level == k){
                sum += newnode->data;
            }
            if(newnode->left){
                q.push(newnode->left);
            }
            if(newnode->right){
                q.push(newnode->right);
            }
        }

        else if(!q.empty()){  // here we no level chnged
            level++;
            q.push(NULL);
        }
    }

    return sum;
}