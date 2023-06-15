#include<iostream>
using namespace std;
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

class BST{
    BinaryTreeNode<int>* root;

    public:

    BST(){
        root = NULL;
    }
    ~BST(){
       delete root;
    }

    private:
    BinaryTreeNode<int>* deleteHelper(int data, BinaryTreeNode<int>* node){
        if(node==NULL){
            return NULL;
        }

        if(data > node->data){
            node->right = deleteHelper(data,node->right);
            return node;
        }else if(data < node->data){
            node->left = deleteHelper(data,node->left);
            return node;
        }else{
            // node->data == data
            // if it leaf node return null
            // if not the replace the root by largest of left side 
            // or replace by smallest of right side
            if(node->left == NULL && node->right==NULL){ // leaf node
                delete node;
                return NULL;
            }else if(node->left == NULL){   // one node is null
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }else if(node->right == NULL){
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }else{     // when the left and right both node is not null
                  
                  // finding the min from right side ...by going left of right we get min of right
                BinaryTreeNode<int>* minNode = node->right;

                while(minNode->left!=NULL){
                    minNode = minNode->left;
                }

                int rightMin = minNode->data; // min of right

                node->data = rightMin;   // replacing

                node->right = deleteHelper(rightMin,node->right); // delete min of right
                return node;
 
            }
        }
    }

    bool searchHelper(int key, BinaryTreeNode<int>* node){
        if(node==NULL){
            return false;
        }
        if(node->data == key){
            return true;
        }

        bool ans;
         if(key<node->data){
            ans = searchHelper(key,node->left);
         }
         else{
            ans = searchHelper(key,node->right);
         }
         return ans;

    }

    public:
    void deleteData(int data){
        root = deleteHelper(data,root);
    }

    bool search(int data){
        return searchHelper(data,this->root);
    }
    

    private:
    BinaryTreeNode<int>* insertHelper(int data, BinaryTreeNode<int>* node){

        if(node==NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if(data < node->data){
            node->left = insertHelper(data,node->left);
            // changing or updating the root of left side
        }else{
            node->right = insertHelper(data,node->right);
        }

        return node;
    }

    public:
    void insert(int data){

        this->root = insertHelper(data, this->root);

    }

    private:
    bool hasData(int data, BinaryTreeNode<int>* root){
       if(root==NULL){
          return false;
        }

       if(root->data == data){
           return true;
       }else if(data<root->data){
           return hasData(data,root->left);
       }else{
            return hasData(data,root->right);
        }
    }

    public:
    bool hasData(int data){
       return hasData(data,root);
    }    
};