#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class ListNode{
    public:
    int val;
    ListNode *next;

    ListNode()
    {
        this->val = 0;
        this->next = NULL;
    }

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
ListNode* reverseLL(ListNode* head)
{
    if(head==NULL)
    return NULL;
    
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forward = curr->next;
    while(curr!=NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
    
int findLL(ListNode* head)
{
    if(head==NULL)
    return 0;

    int count = 0;
    while(head!=NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

void print(ListNode* head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
vector<int> nextLargerNodes(ListNode* head)
{    
    ListNode* temp = reverseLL(head);
    print(temp);
    stack<int> s;

    int len = findLL(temp) - 1;
    // cout<<len;
    vector<int> NGE(len+1,0);
    for(int i= len ; i >= 0; i--)
    { 
        while(!s.empty() && temp->val>=s.top() )
        {
            s.pop();
        }

        if(s.empty())
        {
            NGE[i] = 0;
        }else{
            NGE[i] = s.top();
        }
        s.push(temp->val);

        temp = temp->next;
    }
        return NGE;
}
int main()
{
    ListNode* first = new ListNode(2);
    ListNode* second = new ListNode(1);
    ListNode* third = new ListNode(5);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);

    first->next= second;
    second->next= third;
    // third->next=fourth;
    // fourth->next = fifth;

    vector<int> ans = nextLargerNodes(first);

    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}





