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

Node *evenAfterOdd(Node *head)
{
    Node *oddh = NULL;
    Node *oddt = NULL;
    Node *evenh = NULL;
    Node *event = NULL;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (evenh == NULL)
            {
                evenh = temp;
                event = temp;
                temp = temp->next;
            }
            else
            {
                event->next = temp;
                event = temp;
                temp = temp->next;
            }
        }
        else
        {
            if (oddh == NULL)
            {
                oddh = temp;
                oddt = temp;
                temp = temp->next;
            }
            else
            {
                oddt->next = temp;
                oddt = temp;
                temp = temp->next;
            }
        }
    }

    if (evenh == NULL)
    {
        return oddh;
    }
    else if (oddh == NULL)
    {
        return evenh;
    }
    else
    {
        oddt->next = evenh;
        event->next = NULL;
        return oddh;
    }
}