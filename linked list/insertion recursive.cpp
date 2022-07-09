#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

node* insernoderecursive(node* head, int data, int pos){

    if(head==NULL){           // head null and pos==0
        if(pos==0){
            node* newnode = new node(data);
            return newnode;
        }
        return head;
    }

    node* newnode = new node(data);
    if(pos==0){ 
        newnode->next = head;
        head = newnode;
        return head;
    }

    head->next = insernoderecursive(head->next,data, pos-1);
    return head;
}
