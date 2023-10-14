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
node* reverse(node* &head)
{
    node* prev =NULL;
    node* curr = head;
    node* forward = curr->next;

    while(curr!=NULL)
    {
        forward = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forward;
    }

    return prev;
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

    node* newnode = new node(data);
    tail->next = newnode;
    tail = newnode;
}

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
node* addTwoNumbers(node* l1, node* l2) {
    
    l1 = reverse(l1);
    l2 = reverse(l2);

    node* temp1 = l1;
    node* temp2 = l2;
    node* head = NULL;
    node* tail =NULL;
    int carry =0;
    while(temp1!=NULL && temp2!=NULL)
    {   
            int sum = temp1->data + temp2->data + carry;
            int digit = sum%10;
            carry =sum/10;
            insertAtTail(head,tail,digit); 
            temp1 = temp1->next;
            temp2 = temp2->next;
    }
    while(temp1!=NULL)
    {
            int sum = temp1->data + carry;
            int digit = sum%10;
            carry =sum/10;       
            insertAtTail(head,tail,digit);
            temp1 = temp1->next;
    }
    while(temp2!=NULL)
    {
         int sum = temp2->data + carry;
         int digit = sum%10;
         carry =sum/10;       
         insertAtTail(head,tail,digit);
         temp2 = temp2->next;
    }
    if(carry!=0)
    {
        insertAtTail(head,tail,carry);
    }

    head = reverse(head);

    return head;
    }
int main()
{
    node* head = new node(2);
    node* second = new node(4);
    node* third = new node(2);
    node* fourth = new node(3);
    node* fifth = new node(4);
    // node* sixth = new node(0);
    // node* seventh = new node(0);
    // node* eight = new node(0);
    // node* ninth = new node(1);

    head->next = second;
    second->next=NULL;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    // sixth->next = seventh;
    // seventh->next = eight;
    // eight->next = ninth;
    // ninth->next = NULL;
    print(head);
    print(third);
    node* ans = addTwoNumbers(head,third);
    print(ans);

}