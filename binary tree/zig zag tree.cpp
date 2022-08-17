#include<iostream>
using namespace std;
#include<stack>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

void zigZagOrder(BinaryTreeNode<int> *root){

    if(root==NULL){
        return;
    }

    stack<BinaryTreeNode<int>*> currentLevel;
    stack<BinaryTreeNode<int>*> nextLevel;

    bool leftToRight = true;

    currentLevel.push(root);

    while(!currentLevel.empty()){

        BinaryTreeNode<int>* temp = currentLevel.top();
        currentLevel.pop();

        if(temp!=NULL){
            cout<<temp->data<<" ";

            if(leftToRight){
                if(temp->left){
                    nextLevel.push(temp->left);
                }
                if(temp->right){
                    nextLevel.push(temp->right);
                }
            }

            else{
                if(temp->right){
                    nextLevel.push(temp->right);
                }
                if(temp->left){
                    nextLevel.push(temp->left);
                }
            }
        }

        if(currentLevel.empty()){
            cout<<endl;                   // line break after i level
            leftToRight = !leftToRight;  // make leftToRight false
            swap(currentLevel,nextLevel); // swap stack
        }
    }

}