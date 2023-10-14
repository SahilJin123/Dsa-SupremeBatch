#include<bits/stdc++.h>

using namespace std;

vector<int> NextGreater(vector<int> v)
{
    stack<int> s;
    vector<int>ans;
    s.push(-1);
    for(int i =v.size()-1;i>=0;i--)
    {  
        if( v[i]>=s.top())
        {
            // Pop
            while(s.size()>0 && v[i]>=s.top())
            {
                s.pop();
            }
            if(s.empty())
            {
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
        }
        else if( v[i]<s.top()  )
        {
            ans.push_back(s.top());
        }
        s.push(v[i]);
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    vector<int> v={1,3,2,4};
    vector<int> ans= NextGreater(v);
    for(int i=0;i<v.size();i++)
    cout<<ans[i]<<" ";
}