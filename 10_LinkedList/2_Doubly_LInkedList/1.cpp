#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class node{

    public:
    int data;
    node* prev;
    node* next;

    node(){
        this->data = 0;
        this->prev=NULL;
        this->next=NULL;
    }

    node(int data){
        this->data = data;
        this->prev=NULL;
        this->next=NULL;
    }
};

void print(node* &head)
{
    node* temp =head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
}

int getLength(node* &head)
{
    node* temp =head;
    int len= 0;
    while (temp!=NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void insertAtHead(node* &head,node* &tail,int data)
{
    if(head==NULL)
    {
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    // STep 1 : Creating a new node
    node* newnode = new node(data);
    // Step 2 : Linking a newnode with the head node
    newnode->next = head;
    head->prev = newnode;
    // Step 4 : Updating the head
    head = newnode;

}

void insertAtTail(node* &head,node* &tail,int data)
{
    if(head==NULL)
    {
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }

     // STep 1 : Creating a new node
    node* newnode = new node(data);
    // Step 2 : Linking a newnode with the tail node
    newnode->prev = tail;
    // Step 3 : Linking a newnode with the tail node
    tail->next = newnode;
    // Step 4 : Updating the tail
    tail = newnode;
}

void insertAtPosition(node * &head,node* &tail,int data,int position )
{
    if(head==NULL)
    {
        node* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    int len = getLength(head);

    if(position==1)
    {
        insertAtHead(head,tail,data);
        return;
    }
    if(position>=len)
    {
        insertAtTail(head,tail,data);
        return;
    }

    int i =1;
    node* prevNode = head;
    while(i<position-1)
    {
        prevNode =prevNode->next;
        i++;
    }
    node* curr = prevNode->next;

    node* newnode = new node(data);
    prevNode->next = newnode;
    newnode->prev = prevNode;
    newnode->next = curr;
    curr->prev = newnode;
}
int main()
{
    node* head = NULL;
    node* tail = NULL;
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,60);
    insertAtTail(head,tail,210);
    insertAtPosition(head,tail,301,4);
    
    print(head);
}