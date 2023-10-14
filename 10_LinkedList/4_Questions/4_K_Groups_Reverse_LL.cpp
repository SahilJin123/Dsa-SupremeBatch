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

node* MiddleLL(node* &head)
{
    if(head==NULL)
    {
        cout<<"LL is empty"<<endl;
        return head;
    }

    if(head->next==NULL)
    {
        return head;
    }

    node* slow = head;
    node* fast = head->next;

    while(fast!=NULL  && slow!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
    }

    return slow;
}

int getLength(node* head)
{
    node* temp = head;
    int i = 0;
    while (temp!=NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
    
}

node* reverseKNodes(node* head,int k)
{
    if(head==NULL)
    {
        cout<<"LL is empt y";
        return NULL;
    }

    int len = getLength(head);
    if(k>len)
    {
        cout<<"Enter the valid value for k ";
        return head;
    }

    // it means number of nodes in ll is >= k

    // Step 1 : reverse first k nodes of LL

    node* prev = NULL;
    node* curr = head;
    node* forward = curr->next;

    int count =0;
    while (count<k)
    {
        forward = curr->next;
        curr->next = prev; 

        prev = curr ;
        curr = forward;
        count++;
    }
     
    // Step 2 :recursive call
    if(forward!=NULL)
    {
        // we still have nodes left to reverse
        head->next = reverseKNodes(forward,k);
    } 

    // STep 3 return head of the modified LL

    return prev;
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

    head=reverseKNodes(head,4);
    
    print(head);
}





node* KGroups(node* head,int k)
{
    if(head==NULL)
    return;

    int len = getLength(head);

    if(k>len)
    {
        return head;
    }

//  reverse first k nodes of LL

    node* prev = NULL;
    node* curr = head;
    
    int count =0;
    node* forward = curr->next;
    while(k>count)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward!=NULL)
    {
        head->next=KGroups(forward,k);
    }
    
   return prev;
    
}