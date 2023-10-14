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

int getLength(Node* head)
{
    Node* temp = head->next;

    int i=1;
    while (temp!=head)
    {
        temp=temp->next;
        i++;
    }

   return i;
    
}

void print(Node* head)
{
    Node *temp = head;
    int len = getLength(head);
    int i=1;
    while (i<=len)
    {
       cout<<temp->data<<" ";
       temp = temp->next;
       i++;
    }    
    cout<<endl;
}

void insertAtHead(Node* &head,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    Node* newnode = new Node(data);
    newnode->next = head;
    head = newnode;
}


void insertAtTail(Node* &head,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    Node* newnode = new Node(data);
    tail->next = newnode;
    tail = newnode;
    tail->next = head;
}
void insertAtValue(Node* &head,Node* tail,int data,int value)
{
    if(head==NULL)
    {
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    Node* temp = head;
    int len = getLength(head);
    int i=1;
    while(i<=len)
    {
        if(temp->data==value)
        {
            // Node* nextnode=temp->next;

            Node* newnode = new Node(data);
            
            newnode->next=temp->next;
            temp->next = newnode;
            break;
        }
        else{
            temp = temp->next;
        }
        i++;
    }
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

    cout<<getLength(head)<<endl;
     print(head);
    insertAtValue(head,tail,33,77);
    print(head);
}