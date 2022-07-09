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

Node* mergerecursive(Node* head1, Node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    Node* result;
    if(head1->data < head2->data){
        result = head1;
        return mergerecursive(head1->next, head2);
    }else{
        result=head2;
        return mergerecursive(head1,head2->next);
    }    
    return result;
}

Node* iterative(Node* head1, Node* head2){

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    Node* newhead = NULL;
    Node* newtail = newhead;

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
             head1 = head1->next;
             newtail = newtail->next;
        }else{
            newtail->next=head2;
            newtail = newtail->next;
            head2=head2->next;
        }
    }

    if(head1 !=NULL){
        newtail->next = head1;
    }
    if(head2!=NULL){
        newtail->next=head2;
    }
    return newhead;
}

