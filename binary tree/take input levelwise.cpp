#include<iostream>
using namespace std;
#include<queue>

template<typename T>

class binaryTreeNode{
    public:
    T data;
    binaryTreeNode* left;
    binaryTreeNode* right;

    binaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binaryTreeNode(){
        delete left;
        delete right;
    }
};

binaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"enter root data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }

    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);

    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter left child" <<front->data<<endl;

        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout<<"enter right child of"<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }

    return root;

}

