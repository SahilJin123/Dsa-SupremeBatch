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

node* reverse(node* head)
{
    node* prev = NULL;
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
bool checkPalindrome(node* head)
{
    if(head==NULL)
    {
        cout<<"LL is empty";
        return true;
    }
     if(head->next==NULL)
    {
        return true;
    }

    // STep A : Find the middle Node

        node* slow=head;
        node* fast=head;

        while(fast!=NULL)
        {
            fast = fast->next;
            if(fast!=NULL && fast->next!=NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        // SLow Pointer is Pointing to middle
        
        // Step B: reverse the Linked List

        node* reverseLLKaHead = reverse(slow->next);

        slow->next = reverseLLKaHead;

        // Step c: start Comparison 

        node* temp1 = head;
        node* temp2 = reverseLLKaHead;

        while(temp2!=NULL)
        {
            if(temp1->data!=temp2->data)
            {
                // Not a palindrome
                return false;
            }else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }

        return true;

}


int main()
{
    node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(20);
    node* fifth = new node(10);
    // node* sixth = new node(60);
    // node* seventh = new node(70);
    // node* eight = new node(80);
    // node* ninth = new node(90);

    head->next = second;
    second->next=third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    // sixth->next = seventh;
    // seventh->next = eight;
    // eight->next = ninth;
    // ninth->next = NULL;
   
   bool isPalindrome = checkPalindrome(head);

   if(isPalindrome)
   {
    cout<<"Palindrome";
   }else{
    cout<<"Not Palindrome";
   }
}