#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std ;

void InsertAtBottom(stack<int>& s,int target)
{
    if(s.size()==0)
    {
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();

    InsertAtBottom(s,target);

    s.push(temp);
}
void reverseStack(stack<int> &s)
{
    //  base case
    if(s.empty())
    return;

    int target = s.top();
    s.pop();

    // reverse stack
    reverseStack(s);
    // insert at bottom target ko 
    InsertAtBottom(s,target);

}
int main()
{
    
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    
    reverseStack(s);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}