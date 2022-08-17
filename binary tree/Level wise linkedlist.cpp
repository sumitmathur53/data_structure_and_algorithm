#include<iostream>
using namespace std;
#include<queue>
#include<vector>

template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root){

    vector<Node<int>* > output;

    if(root==NULL){
        return output;
    }

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    int currentLevelRemaining=1;
    int nextLevelCount = 0;

    Node<int>* currentLevelHead = NULL;
    Node<int>* currentLevelTail = NULL;

    while(!q.empty()){
        BinaryTreeNode<int> *newnode = q.front();
        q.pop();

        Node<int> * front = new Node<int>(newnode->data);

        if(currentLevelHead==NULL){
            currentLevelHead = front;
            currentLevelTail = front;
        }else{
            currentLevelHead->next = front;
            currentLevelTail = front;
        }

        if(newnode->left !=NULL){
            q.push(newnode->left);
            nextLevelCount++;
        }
        if(newnode->right!=NULL){
            q.push(newnode->right);
            nextLevelCount;
        }
        currentLevelRemaining--;

        if(currentLevelRemaining==0){
            output.push_back(currentLevelHead);
            currentLevelHead=NULL;
            currentLevelTail=NULL;
            currentLevelRemaining = nextLevelCount;
            nextLevelCount=0;
        }
    }
    
}