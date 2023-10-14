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

bool checkforLoop(node* head)
{
    if(head==NULL)
    {
        cout<<"LL is empty "<<endl;
        return false;
    }

    node* slow = head;
    node* fast = head;
    
    while (fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }

        if(slow==fast) return true;
    }

    return false;
    
}

node* StartingPoint(node* head)
{   
    if(head==NULL)
    {
        // cout<<"LL is empty "<<endl;
        return NULL;
    }
    // if(!checkforLoop(head))
    // return head;

// ********************************************** Yeh code bhi chalta hai *********************************************

    // node* slow = head->next;
    // node* fast = head->next->next;

    // while (fast!=slow)
    // {
    //     fast = fast->next->next;
    //     slow = slow->next;
    // }

    // slow = head;

    // while (fast!=slow)
    // {
    //     fast = fast->next;
    //     slow = slow->next;
    // }
    
    // return slow;


// ********************************************** Yeh code bhi chalta hai *********************************************


    node* slow = head;
    node* fast = head;
    
    while (fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }

        if(slow==fast) 
        {
            slow = head;
            break;
        }
    }

    while(slow!=fast)
    {
        fast=fast->next;
        slow=slow->next;
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
    node* seventh = new node(70);
    node* eight = new node(80);
    node* ninth = new node(90);

    head->next = second;
    second->next=third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = ninth;
    ninth->next = sixth;
    bool ans = checkforLoop(head);
    cout<<"Loop is Present or Not : "<<ans<<endl;

    if(ans)
    {
       cout<<"Starting Point is: "<<StartingPoint(head)->data; 
    }
    else{
        cout<<"Starting Point is: "<<head->data;
    }
    

    // print(head);
}