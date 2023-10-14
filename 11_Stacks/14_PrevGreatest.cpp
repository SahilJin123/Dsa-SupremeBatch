#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std ;

vector<int> PrevGreatest(vector<int> arr)
{
    vector<int> ans;
    stack<int> s;
    // s.push(-1);

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>s.top() && s.size()>0)
        {
            // Pop  
            while(arr[i]>s.top() && s.size()>0)
            {
                s.pop();
            }
            // Empty
            if(s.size()==0)
            {
                ans.push_back(-1);
            }
        }
        else if(s.top()>arr[i])
        {
            // push s.top() in ans[i]
            ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
}
int main()
{
    
    vector<int> v{1,3,2,4};
    vector<int> ans = PrevGreatest(v);

    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}