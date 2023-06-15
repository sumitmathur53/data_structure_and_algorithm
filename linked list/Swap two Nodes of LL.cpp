#include <iostream>
#include<limits.h>
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


Node* swap(Node* head, int i, int j){
    int x = min(i,j);
    int y = max(i,j);

    Node* p1 = head;
    Node* p2 = head;
    Node* c1 = head;
    Node* c2 = head;

    if(x==0){
        c1 = head;
    }
}