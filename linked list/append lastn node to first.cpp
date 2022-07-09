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

int length(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    return 1 + length(head->next);
}

Node *appendLastNToFirst(Node *head, int n)
{
    int l = length(head);

    if (n == 0 || n == 1 || l < n)
    {
        return head;
    }

    Node *newhead = NULL;
    Node *newtail = NULL;

    Node *tail = head;

    int count = 1;

    while (tail->next != NULL)
    {
        if (count == l - n)
        {
            newtail = tail;
        }
        if (count == l - n + 1)
        {
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }

    newtail->next = NULL;
    tail->next = head;

    return newhead;
}