#include<iostream>
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

Node* merge(Node* head1, Node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    Node* newhead = NULL;
    Node* newtail = NULL;

    if(head1->data < head2->data){
        newhead = head1;
        newtail = head1;
        head1=head1->next;
    }else{
        newhead = head2;
        newtail = head2;
        head2 = head2->next;
    }

    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            
            newtail->next = head1;
            newtail = head1;
            head1 = head1->next;
        }else{
            
            newtail->next = head2;
            newtail = head2;
            head2 = head2->next;
        }

    }

    if(head1!=NULL){
        newtail->next= head1;
    }
    if(head2!=NULL){
        newtail->next = head2;
    }
    return newhead;
}

Node* findmid(Node* head){
    if(head==NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast->next!=NULL and fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergSort(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* mid = findmid(head);
    Node* half1 = head;
    Node* half2 = mid->next;
    mid->next = NULL;

    half1 = mergSort(half1);
    half2 = mergSort(half2);

    return merge(half1,half2);
}