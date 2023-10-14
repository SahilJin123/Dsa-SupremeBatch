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

void removeDuplicates(node* head)
{
    node* curr = head;

    while(curr!=NULL  && curr->next!=NULL)
    {
        if(curr->data!=curr->next->data)
        {
            curr = curr->next;
        }else{
            node* temp = curr->next;
            curr->next = curr->next->next;
            
            // delete the node
            temp->next = NULL;
            delete temp;
        }
    }
}


int main()
{
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(2);
    node* fourth = new node(2);
    node* fifth = new node(2);
    node* sixth = new node(4);
    node* seventh = new node(4);
    node* eight = new node(5);
    node* ninth = new node(5);

    head->next = second;
    second->next=third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = ninth;
    ninth->next = NULL;
   
   print(head);

   removeDuplicates(head);
   print(head);
}