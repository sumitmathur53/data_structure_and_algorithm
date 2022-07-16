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

Node* skipmdeleten(Node*head, int m, int n){

    Node* current = head;
    Node* temp = NULL;
    int count;

    if(head==NULL){
        return NULL;
    }

    while(current!=NULL){

        for(count=1;count<m && current!=NULL;count++){
            current=current->next;
        }

        if(current==NULL){
            return head;
        }

        temp = current->next;

        for(count=1;count<=n && temp!=NULL;count++){
            Node* todelete = temp;
            temp = temp->next;
            delete(todelete);
        }

        current->next = temp;
        current = temp;
    }
    return head;
}