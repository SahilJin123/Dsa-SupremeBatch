#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std ;
int main()
{
    priority_queue<int> pq;  //max heap is created 
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);
    // pq.push(3);

    cout<<"Top Element is : "<<pq.top()<<endl; 
    pq.pop();
    cout<<"Top Element is : "<<pq.top()<<endl; 
    pq.pop();
    cout<<"Top Element is : "<<pq.top()<<endl; 
    pq.pop();
    cout<<"Top Element is : "<<pq.top()<<endl; 
    pq.pop();
    cout<<"Top Element is : "<<pq.top()<<endl; 
    pq.pop();
    cout<<"Size is: "<<pq.size()<<endl;
    if(pq.empty())
    {
        cout<<"Max Heap is Empty"<<endl;
    }else{
        cout<<"Max Heap is not Empty"<<endl;
    }
}