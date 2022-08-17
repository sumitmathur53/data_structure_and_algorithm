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

void printLevelWise(Binarytree<int>* root){
    if(root==NULL){
        return;
    }

    queue<Binarytree<int>*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Binarytree<int>* newnode = q.front();
        q.pop();

        if(newnode!=NULL){
            cout<<newnode->data<<" ";
            if(newnode->left){
                q.push(newnode->left);
            }
            if(newnode->right){
                q.push(newnode->right);
            }
        }
        else if(!q.empty()){
            cout<<endl;
            q.push(NULL);
        }

    }
}