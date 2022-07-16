#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

int length(Node* head){
    Node* temp = head;
    if(temp==NULL){
        return 0;
    }

    return 1+length(temp->next);
}

Node *bubble_sort(Node* head){

    for(int i=0;i<length(head);i++){
        Node* curr = head;
        Node* prev = NULL;

        while(curr->next!=NULL){
            if(curr->data > curr->next->data){

                if(prev!=NULL){
                    Node* temp = curr->next->next;
                    curr->next->next = curr;
                    prev->next = curr->next;
                    curr->next = temp;
                    prev = prev->next;
                }else{
                    head = curr->next;
                    curr->next = head->next;
                    head->next = curr;
                    prev = head;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
    }
    return head;
}