#include<iostream>
using namespace std;

template<typename T>

class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

template<typename T>

class Node{
    public:
    T data;
    Node<T>* next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

class Pair{
    public:
    Node<int>* head;
    Node<int>* tail;
};

Pair Bst(BinaryTreeNode<int>* root){
     
     if(root==NULL){
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
     }

     Node<int>* newnode = new Node<int> (root->data);

     Pair leftAns  = Bst(root->left);
     Pair rightAns = Bst(root->right);

     Pair ans;

     if(leftAns.head == NULL && rightAns.head==NULL){
        ans.head = newnode;
        ans.tail = newnode;
     }

     else if(leftAns.head==NULL && rightAns.head){
        ans.head = newnode;
        newnode->next = rightAns.head;
        ans.tail = rightAns.tail;
     }

     else if(leftAns.head && rightAns.head==NULL){
        ans.head = leftAns.head;
        leftAns.tail->next = newnode;
        ans.tail = newnode;
     }

     else{
        ans.head = leftAns.head;
        leftAns.tail->next = newnode;
        newnode->next = rightAns.head;
        ans.tail = rightAns.tail;
     }

     return ans;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    return Bst(root).head;
    
}