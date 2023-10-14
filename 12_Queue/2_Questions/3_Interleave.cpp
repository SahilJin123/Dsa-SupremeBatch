#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std ;

void Interleave(queue<int> &q)
{   
    if(q.size()==0)
    {
        cout<<"Queue is empty";
        return;
    }
    int mid = (q.size()+1)/2;

    queue<int> temp;

    while(mid)
    {
        temp.push(q.front());
        q.pop();
        mid--;
    }

    int n = q.size();

    while(n)
    {
        int sample = q.front();
        q.pop();
        q.push(temp.front());
        temp.pop();
        q.push(sample);
        n--;
    }

    if(!temp.empty())
    {
        q.push(temp.front());
    }
}
int main()
{
    queue<int> q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // q.push(70);
    // q.push(80);
    // q.push(90);
    // q.push(100);

    Interleave(q);

    // while (!q.empty())
    // {
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
}