#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std ;

void solve(vector<int>v,vector<int>&ans)
{
    stack<int> s;
    s.push(-1);
    for(int j =v.size()-1;j>=0;j-- )
    {   
        int curr = v[j];
        while(s.top()>=curr){
            s.pop();
        }
        ans[j] = s.top();
        s.push(curr);
    } 
}
int main()
{
    
    vector<int> v{2,1,5,6,2,3};
    vector<int>ans(v.size());
    solve(v,ans);

     for(auto it:ans)
     {
        cout<<it<<" ";
     }
}