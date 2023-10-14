#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std ;

// ************************ Reverese Using Stack ******************
// void reverse(queue<int> &q)
// {
//     stack<int> s;

// // Step 1 Push all elements of queue in stack
//     while (!q.empty())
//     {
//         s.push(q.front());
//         q.pop();
//     }
// // Step 2 Push all elements of  stack in queue 
//     while (!s.empty())
//     {
//         q.push(s.top());
//         s.pop();
//     }
    
// }
// ************************ Reverese Using Recursion ******************

void reverse(queue<int> &q)
{
    if(q.empty())
    return;
    
    int temp = q.front();
    q.pop();

    reverse(q);

    q.push(temp);
}
int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);

    reverse(q);

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
}