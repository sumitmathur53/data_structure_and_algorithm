#include<iostream>
#include<vector>
using namespace std;
#include<queue>

template<typename T>

class treenode{
    public:
    T data;
    vector<treenode<T>*> children;  // writing T is optional it by default assume it
    
    treenode(T data){
        this->data = data;
    }

};

void printTree(treenode<int>* root){

    if(root==NULL){  // it is edge case not base case
        return;
    }
    cout<<root->data<<":";  // this self acting as base case
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }

}
// to give input user must know about how recursion work 
// so we think other way as levelwiseinput
treenode<int>* takeInput(){   // it hard for user to input
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;

    treenode<int>* root = new treenode<int>(rootData);

    int n;
    cout<<"enter num of children of"<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        treenode<int>* child = takeInput();
        root->children.push_back(child);
    }

    return root;

}
// for level wise input we use queue
treenode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"enter root data"<<endl;
    cin>>rootData;
    treenode<int>* root = new treenode<int>(rootData);

    queue<treenode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        treenode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter num of children of"<<front->data<<endl;

        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter"<<i<<"th child of"<<front->data<<endl;
            cin>>childData;
            treenode<int>* child = new treenode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    
    return root;

}

int main(){
    // treenode<int> * root = new treenode<int>(1);
    // treenode<int> * node1 = new treenode<int>(2);
    // treenode<int> * node2 = new treenode<int>(3);

    // root->children.push_back(node1);
    // root->children.push_back(node2);

    treenode<int> *root = takeInput();

    printTree(root);
    treenode<int> *root1 = takeInputLevelWise();
    printTree(root1);

    // todo to delete 


}