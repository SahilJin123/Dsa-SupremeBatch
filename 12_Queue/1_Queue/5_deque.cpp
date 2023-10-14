#include<iostream>
#include<bits/stdc++.h>
#include<deque>

using namespace std ;
int main()
{
    deque<int> dq;

    dq.push_front(5);
    dq.push_front(10);
    dq.push_back(20); 
    dq.push_back(30);

    cout<<dq.size();
    dq.pop_front();
    cout<<dq.size();
}