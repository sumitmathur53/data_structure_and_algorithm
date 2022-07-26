#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};



class stack{
    Node* head;
    int sizeo;  // number of elements present in stack

    public:

    stack(){
        head = NULL;
        sizeo=0;
    }

    int getsize(){
        return sizeo;
    }

    bool isempty(){
        return sizeo==0;
    }

    void push(int element){
        Node* newnode = new Node(element);
        newnode->next = head;
        head = newnode;
        sizeo++;
    }

    int pop(){
        if(isempty()){
            return 0;
        }
        int ans = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        sizeo--;
        return ans;
    }

    int top(){
        if(isempty()){
            return 0;
        }
        return head->data;
    }

};