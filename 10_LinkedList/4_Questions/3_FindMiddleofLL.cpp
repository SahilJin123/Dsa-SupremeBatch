#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class node{

    public:
    int data;
    node* next;

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

void print(node* &head)
{
    node* temp = head;

    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


node* MiddleLL(node* head)
{
    if(head==NULL)
    return NULL;
    
    node* slow = head;
    node* fast = head;

    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
int main()
{
    node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
    node* fifth = new node(50);
    node* sixth = new node(60);
    head->next = second;
    second->next=third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    print(head);

    cout<<"Middle Node is : " <<MiddleLL(head)->data<<endl;
}