#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

int find(node* head, int n){
    int count =0;

    node* temp = head;
    while(temp!=NULL){
        if(temp->data==n){
            return count;
        }
        count++;
        temp=temp->next;
    }
    return -1;
}

int findnoderecurrsive(node* head , int n){

    if(head==NULL){
        return -1;
    }else if(head->data==n){
        return 0;
    }
    
    int count = 1;

    int small = findnoderecurrsive(head->next,n);

    if(small==-1){
        return -1;
    }
    return small+count;
}