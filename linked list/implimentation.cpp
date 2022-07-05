#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

void print(node* head){
   node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

node* takeinput(){   // time complexity o(n^2)
    int data;
    cin>>data;
    node* head = NULL;
    while(data!=-1){
        node* newnode = new node(data);
        if(head==NULL){
            head = newnode;
        }
        else{
            node * temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
        cin>>data;
    }
    return head;
}

node* takeinputbeter(){  // time complexity o(n)
    int data;
    cin>>data;
    node* head = NULL;
    node* tail = NULL;
    while(data!=-1){
        node* newnode = new node(data);
        if(head==NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

int main(){

    node *head = takeinputbeter();
    print(head);

    // statically craeting node
    // node n1(1);
    // node* head = &n1;   
    // node n2(2);
    // node n3(3);
    // node n4(4);
    // node n5(5);

    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    // print(head);

    // n1.next = &n2;
    // cout<<n1.data<<" "<<n2.data<<endl;

    // // dynamically
    // node* n3 = new node(10);
    // node* head = n3;
    // node* n4 = new node(20);
    // n3->next = n4;  // linking node
}
