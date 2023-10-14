#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std ;
int main()
{  
    string st = "Sahil";
   stack<char> s;

   for(int i=0;i<st.length();i++)
   {
     s.push(st[i]);
   }

   while(!s.empty())
   {
    cout<<s.top()<<endl;
    s.pop();
   }
}