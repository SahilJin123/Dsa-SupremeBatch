#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std ;

void solve(stack<int>& s,int target)
{
    if(s.size()==0)
    {
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();

    solve(s,target);

    s.push(temp);
}

void InsertBottom(stack<int>& s)
{
    if(s.empty())
    {
        cout<<"Stack is empty";
        return;
    }

    int target = s.top();
    s.pop(); 

    solve(s,target);
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
    
    InsertBottom(s);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}