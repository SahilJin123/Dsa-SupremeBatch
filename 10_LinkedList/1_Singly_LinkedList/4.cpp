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

    ~node()
    {
          
    }
};

void print(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void insertAtHead(node* &head,node* &tail,int data)
{
    if(head==NULL)
    {
        node* newNode = new node(data);
        tail = newNode;
        head = newNode;
        return;
    }
    node* newNode = new node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(node* &head,node* &tail,int data)
{
    if(head==NULL)
    {
        node* newNode = new node(data);
        tail = newNode;
        head = newNode;
        return;
    }
    node* newNode = new node(data);
    tail->next = newNode;
    tail = newNode;
}

int findLLlength(node* head)
{
    int len =0;
    node* temp = head;
    while (temp!= NULL)
    {
        temp=temp->next;
        len++;
    }

    return len;
}
void insertAtPosition(node* head,node* tail,int data,int position)
{
    if(head==NULL)
    {
        node* newNode = new node(data);
        tail = newNode;
        head = newNode;
    }
    // STep 1: Find the Position: prev & curr
    if(position==0)
    {
        insertAtHead(head,tail,data);
        return;
    }

    int len = findLLlength(head);
    if(position>=len)
    {
        insertAtTail(head,tail,data);
        return;   
    }
    int i =1;
    node * prev = head;
    while(i<position)
    {
        prev = prev->next;
        i++;
    }
    
    node* curr = prev->next;
    // Step 2: Create a Node
    node* newNode = new node(data);
    // Step 3 connecting newnode with current node
    newNode->next  = curr;
    // // Step 3 connecting newnode with prev node
    prev->next = newNode;
}


void deleteNode(node* &head,node* &tail,int position)
{
    if(head==NULL)
    {
        cout<<"Can't delete, LL is empty"
        return;
    }

    if(position==1)
    {

        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int len = findLLlength(head);

    if(position>=len)
    {
        node* prev = head;
        int i=1;
        while(position-1>i)
        {
            prev = prev->next;
            i++;
        }
        // find prev
        prev->next = NULL;
        // step 3
        node*temp =tail;
        // step 4
        tail = prev;
        // step 5
        delete temp;
        return;
    }

    // deleting Middle Node

    // Step : find prev and current

    int i=1;
    node* prev = head;
    while(i<position-1)
    {
        prev = prev->next;
        i++;
    }
    node * curr = prev->next;
    prev->next = curr->next;

    curr->next = NULL;

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
    insertAtTail(head,tail,77);
     print(head);
    insertAtPosition(head,tail,33,90);
    cout<<"Printing the Linked List at Head: "<<endl;
    print(head);
}