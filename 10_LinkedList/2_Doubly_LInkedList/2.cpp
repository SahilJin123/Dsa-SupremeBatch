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

    ~node()
    {
        // Todo : write code to delete the node
        // cout<<"Node with value: "<<this->data<<" deleted"<<endl;
        prev = NULL;
        next = NULL;
        delete prev;
        delete next;

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

    cout<<endl;
    
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

void deleteFromPos(node * &head,node* &tail,int position)
{
    if(head==NULL)
    {
        cout<<"LL is Empty"<<endl;
        return;
    }
    if(head->next==NULL)
    {
        node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    if(position==1)
    {
        node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = getLength(head);

    if(position>=len)
    {
        node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }
     
    //  STep 1: find left,curr & right
    int i=1;
    node* left = head;
    while (i<position-1)
    {
        left = left->next;
        i++;
    }
    node* curr = left->next;
    node* right = curr->next;
    // Step 2
    left->next = right;
    // Step 3
    right->prev = left;
    // Step 4
    curr->prev = NULL;
    // Step 5
    curr->next = NULL;
    // Step 6
    delete curr;

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

    deleteFromPos(head,tail,4);
    
    print(head);
}