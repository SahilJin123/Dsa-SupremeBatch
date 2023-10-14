#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class node{
    public:
    int data;
    node* next ;

    node()
    {
        this->data = 0;
        this->next = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


void print(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insertAtHead(node* head,node* tail,int data)
{
    if(head==NULL)
    {
        node* newnode = new node(data);
        head=newnode;
        tail = newnode;
        return;
    }

    node* newnode = new node(data);

    newnode->next = head;
    head = newnode;

}

void insertAtTail(node* head,node* tail,int data)
{
    if(head==NULL)
    {
        node* newnode = new node(data);
        head=newnode;
        tail = newnode;
        return;
    }

    node* newnode = new node(data);

    tail->next = newnode;
    tail = newnode;

}

int findLengthLL(node* head)
{
    node* temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}

void insertAtPosition(node* head,node* tail,int data,int Position)
{
    if(head==NULL)
    {
        node* newnode = new node(data);
        head=newnode;
        tail = newnode;
        return;
    }

    if(Position==0)
    {
        insertAtHead(head,tail,data);
        return;
    }

    int len = findLengthLL(head);

    if(Position>=len)
    {
        insertAtTail(head,tail,data);
        return;
    }

    int i = 1;
    node* prev = head;
    while(i<Position)
    {
        prev = prev->next;
        i++;
    }

    node* newnode = new node(data);

    node* curr = prev->next;

    newnode->next = curr;

    prev->next = newnode;

    return;
}

void deleteNode(node* head,node* tail,int data,int Position)
{
    if(head==NULL)
    return;

    if(Position==1)
    {
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        return;
    }

    int len = findLengthLL(head);

    if(Position>=len)
    {
        int i=1;
        node * prev = head;
        while(i<Position-1)
        {
            prev = prev->next;
            i++;
        }
        
        node* temp = prev->next;
        prev->next = NULL;
        tail = prev;

        delete temp;
        return;
    }


    node * prev = head;
    int i=1;
    while(i<Position-1)
    {
        prev=prev->next;
        i++;
    }

    node* curr = prev->next;

    prev->next = curr->next;

    curr->next = NULL;
    delete curr;
    return;
}


node* reverseLL(node* prev,node* curr)
{
    if(curr==NULL)
    return prev;

    node* forward = curr->next;
    curr->next=prev;
    prev = curr;
    curr = forward;
    reverseLL(prev,curr);
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
    insertAtTail(head,tail,77);  
    insertAtPosition(head,tail,33,90);
    print(head);
    node* prev = NULL;
    node* curr = head;
    head=reverseLL(prev,curr);
    cout<<"Printing the Reverse Linked List : "<<endl;
    print(head);
    
}