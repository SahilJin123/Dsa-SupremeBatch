#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
  // Creation of Queue
   queue<int> q;


  //  Insertion Of queue
   q.push(4);
   q.push(5);
   q.push(6);
   q.push(7);
   q.push(8);
   q.push(9);
   q.push(10);
   q.push(11);

  // Size of Queue

  cout<<"Size of Queue is: "<<q.size()<<endl;

  // Removal
   q.pop();

   if(q.empty())
   {
    cout<<"Queue is empty";
   }
   else{
    "Not Empty"<<endl;
   }

   cout<<"Front Element is : "<<q.front(); 
   
   
}