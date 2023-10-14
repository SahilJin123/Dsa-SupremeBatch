#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std ;

void solve(stack<int> s,int size)
{
    if(s.size()==0)
    {
        cout<<"There is No element in stack";
        return;
    }
    // Base Case
    if((size+1)/2==s.size())
    {
        cout<<"Middle Element is: "<<s.top();
        return;
    }

    // Processing 
    int temp=s.top();
    s.pop();
    
    // Recursive call
    solve(s,size);

    // Backtracking
    s.push(temp);
}
int main()
{
    stack<int> s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // s.push(60);
    // s.push(70);

    solve(s,s.size());
}