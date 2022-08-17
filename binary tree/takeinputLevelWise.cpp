#include<iostream>
using namespace std;
#include<queue>

template<typename T>

class binaryTreeNode{
    public:
    T data;
    binaryTreeNode<T>* left;
    binaryTreeNode<T>* right;

    binaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binaryTreeNode{
        delete left;
        delete right;
    }
};

void printLevelWise(binaryTreeNode<int>* root, int x){
    if(root==NULL){
        return ;
    }

    queue<binaryTreeNode<int>*> q;
    q.push(root);

    while(q.size()!=0){
        binaryTreeNode<int>* front = q.front();
        q.pop();
        cout<<front->data<<" ";

        if(front->left){
            q.push(front->left);
            cout<<front->left->data<<" ";
        }
        if(front->right){
            q.push(front->right);
            cout<<front->right->data<<" ";
        }

    }
}