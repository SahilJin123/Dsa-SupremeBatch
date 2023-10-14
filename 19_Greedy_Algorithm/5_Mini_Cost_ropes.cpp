// Gfg Minimum cost of ropes

#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std ;
int main()
{
    int ropes[] = {4,3,2,6};
    int n = 4;

    priority_queue<int,vector<int>,greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(ropes[i]);
    }

    int cost =0;
    while(pq.size()!=1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int total = a+ b;
        cost+= total;
        pq.push(total);
    }

    cout<<cost;
    
}