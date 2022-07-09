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
Node *removeDuplicates(Node *head)
{
    Node* current = head;
    
    if(current==NULL){
        return head;
    }
    
    while(current->next != NULL){
        if(current->data == current->next->data){
              current->next = current->next->next;
        }else{
            current=current->next;
        }
    }
    
    return head;
}
