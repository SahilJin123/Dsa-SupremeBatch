#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class Node{
    public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head)
{
    Node *temp = head;

    while (temp!=NULL)
    {
       cout<<temp->data<<" ";
       temp = temp->next;
    }    
}

// I want to insert a node right at he head
void insertAtHead(Node* &head,Node* &tail,int data)
{
    
    // Check if Linked List is empty
    if(head==NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }
    // Step 1 :- Create a node
    Node* newNode = new Node(data);
    // Inserting address of Head in the newNode next cell 
    newNode->next = head;
    // Moving the head to newNode
    head = newNode;

}
void insertAtTail(Node* &head,Node* &tail,int data)
{
    // Check if Linked List is empty
    if(head==NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,60);
    insertAtTail(head,tail,77);
    

    cout<<"Printing the Linked List at Head: "<<endl;
    print(head);

    // cout<<"Printing the Linked List at Head: "<<endl;
    // print(head);
    // insertAtTail(head,20);
    // insertAtTail(head,30);
    // insertAtTail(head,40);
    // insertAtTail(head,50);
    // insertAtTail(head,60);
}       