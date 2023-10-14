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

node* Sort_0_1_2(node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    node* zerohead= new node(-1);
    node* zerotail= zerohead;
    node* onehead = new node(-1);
    node* onetail = onehead;
    node* twohead = new node(-1);
    node* twotail = twohead;

    node* curr = head;

    while (curr!=NULL)
    {
        if(curr->data==0)
        {   
            node* temp = curr;

            curr = curr->next;
            temp->next = NULL;
            
            // append zero node inzerohead LL
            zerotail->next = temp;
            zerotail = temp;
        }else if(curr->data==1)
        {
            node* temp = curr;

            curr = curr->next;
            temp->next = NULL;
            
            // append zero node inzerohead LL
            onetail->next = temp;
            onetail = temp;
        }else{
            node* temp = curr;

            curr = curr->next;
            temp->next = NULL;
            
            // append zero node inzerohead LL
            twotail->next = temp;
            twotail = temp;
        }   
    }

    // ab yaha par tino LL ready hai
    

    // modify one waali list
    node* temp = onehead;
    onehead = onehead->next;
    temp->next = NULL;
    delete temp;

    temp = twohead;
    twohead = twohead->next;
    temp->next = NULL;
    delete temp; 

    // return head of the modified linked list

    if(onehead!=NULL)
    {
        zerotail->next = onehead;
       if(twohead!=NULL)
        {
            onetail->next = twohead;
        }
    }else{
        if(twohead!=NULL)
        {
            zerotail->next = twohead;
        }
    } 

    temp = zerohead;
    zerohead = zerohead->next;
    temp->next= NULL;
    delete temp;

    return zerohead;   

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
    node* head = new node(2);
    node* second = new node(2);
    node* third = new node(2);
    node* fourth = new node(1);
    node* fifth = new node(1);
    node* sixth = new node(1);
    node* seventh = new node(1);
    node* eight = new node(2);
    node* ninth = new node(2);

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

    node* ans = Sort_0_1_2(NULL);

    print(ans);

}