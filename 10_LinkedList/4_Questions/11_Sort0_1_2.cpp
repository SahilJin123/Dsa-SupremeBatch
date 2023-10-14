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

void Sort_0_1_2(node* head)
{
    int zeroCount=0;
    int oneCount =0;
    int twoCount =0;

    node* temp = head;

    while (temp!=NULL)
    {
        if(temp->data==0)
        {
            zeroCount++;
        }else if(temp->data==1)
        {
            oneCount++;
        }else{
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;

    while(temp!=NULL)
    {
         if(zeroCount>0)
        {
            temp->data =0;
            zeroCount--;
        }else if(oneCount>0)
        {
            temp->data=1;
            oneCount--;
        }else{
            temp->data=2;
            twoCount--;
        }
        temp = temp->next;
    }
    

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


int main()
{
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(2);
    node* fourth = new node(0);
    node* fifth = new node(2);
    node* sixth = new node(0);
    node* seventh = new node(0);
    node* eight = new node(0);
    node* ninth = new node(1);

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

    Sort_0_1_2(head);

    print(head);

}