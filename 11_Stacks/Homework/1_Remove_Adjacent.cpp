#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
void removeDuplicates(string s) {

    stack<char> ans;
    for(int i=0;i<s.length();i++)
    {
        if(!ans.empty() && s[i]==ans.top())
        {
            ans.pop();
        }else{
            ans.push(s[i]);
        }
    }

    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }


}
int main()
{
   string a = "abbaca";
   removeDuplicates(a);
}