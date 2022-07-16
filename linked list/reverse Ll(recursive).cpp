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
        this->next = NULL;
    }
};

Node *reverseLinkedListRec(Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node* newhead = reverseLinkedListRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

Node* reverse(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }

    Node* small = reverse(head->next);
    Node* temp = small;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return small;
}