#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

};

int maxPath_util(Node* root, int &ans){

    if(root==NULL){
        return 0;
    }

    int left1 = maxPath_util(root->left,ans);
    int right2 = maxPath_util(root->right,ans);

    int nodeMax = max(max(root->data,root->data+left1+right2), 
    max(root->data+left1,root->data+right2));


    ans = max(ans,nodeMax);

    int singlepathsum = max(root->data , max(root->data+left1,root->data + right2));

    return singlepathsum;

}

int maxPathSum(Node* root){

    int ans = INT_MIN;

    maxPath_util(root,ans);

    return ans;
}