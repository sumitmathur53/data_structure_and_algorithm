#include<iostream>
using namespace std;

class node{
    public:

    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

node* takeinput(){  // taking input till -1
    int data;
    cin>>data;
    node* head = NULL;

    while(data!=-1){
        node* newnode = new node(data);
        if(head==NULL){
            head = newnode;
        }
        else{
            node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
        cin>>data;
    }

    return head;
}

node* insertnodeatith(node* head, int i, int val){
    
    node* newnode = new node(val);
    int count=0;
    node* temp = head;

    if(i==0){
        newnode->next = head;
        head = newnode;
        return head;  // head is changing here so we need to return it
    }
    while(count < i-1 && temp!=NULL){
        temp = temp->next;
        count++;
    }
    
    if(temp!=NULL){
       node* a = temp->next;  // saving right hand site list in variable
       temp->next = newnode;  // join left to newnode
       newnode->next=a;       // newnode to right
    }
    return head;
    
}

int main(){
    node* head = takeinput();
    print(head);
    int i, data;
    cin>>i>>data;
    head = insertnodeatith(head,i, data);
    print(head);
}