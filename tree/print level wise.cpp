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

void printLevelWise(treenode<int>* root){
    if(root==NULL){
        return;
    }

    queue<treenode<int>*> q;
    q.push(root);

    while(q.size()!=0){
        treenode<int>* front = q.front();
        q.pop();
        cout<<front->data<<":";

        for(int i=0;i<front->children.size();i++){
            if(i==0){
                cout<<front->children[i]->data<<" ";
            }else{
                cout<<","<<front->children[i]->data;
            }
            q.push(front->children[i]);
        }
        cout<<endl;
    }

}

int numNodes(treenode<int>* root){
    int ans = 1;
    for(int i=0;i<root->children.size();i++){
        ans += numNodes(root->children[i]);
    }
    return ans;

}

