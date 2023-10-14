#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std ;

void reverseKelements(queue<int> &q,int k)
{
    if(k==0)
    {
      return;
    }
    
    int temp = q.front();
    q.pop();
    k--;
    reverseKelements(q,k);
    
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
    
    int k =5;

    reverseKelements(q,k);
    
    int i = q.size() - k;
    while(k)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
        k--;
    }
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}