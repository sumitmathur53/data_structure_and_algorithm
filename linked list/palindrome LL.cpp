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

Node* reverse(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;

    }
    return prevptr;
}

bool palindrom(Node* head){
    if(head==NULL || head->next==NULL){
        return true;
    }

    // finding mid point of the LL

    Node* slow = head;
    Node* fast = head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    Node* sechead = slow->next;
    slow->next=NULL;
    sechead = reverse(sechead);

    // now comparing the two list

    Node* head1 = head;
    Node* head2 = sechead;

    bool ans = true;

    while(head2!=NULL){

        if(head1->data!=head2->data){
            ans = false;
            break;
        }

        head1=head1->next;
        head2=head2->next;

    }

    // rejoining the two list

    head1 = head;
    head2 = reverse(sechead);

    while(head1->next!=NULL){
        head1=head1->next;
    }
    head1->next = head2;

    return ans;

}