#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std ;

bool isValid(string s) {
        stack<int> ans;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                ans.push(s[i]);
            }else{
                if(ans.empty())
                return false;

                if(s[i]=='}' && ans.top()=='{')
                {
                    ans.pop();
                }else if(s[i]==')' && ans.top()=='(')
                {
                    ans.pop();
                }else if(ans.top()=='[' && s[i]==']')
                 {
                     ans.pop();
                 }else{
                     return false;
                 }
            }
        }

        if(ans.empty())
        return true;
        else
        return false;
}
int main()
{
   string s ="]";
   bool ans = isValid(s);
   cout<<ans;
}