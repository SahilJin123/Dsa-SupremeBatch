#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std ;

void RedundantBrackets(string& s,stack<char>& st)
{
    int index = -1;
    bool operator1 = false;
    for(int i=0;i<s.length();i++)
    {   
        if(s[i]=='(')
        {
            st.push(s[i]);
            index =i;
        }
        if(st.top()=='(' && (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'))
        {
            operator1 = true;
        }

        if(operator1==true && s[i]==')')
        {
            st.pop();
            operator1 = false;
        }

        if(operator1==false && st.top()=='(' && s[i]==')')
        {
            s.erase(index,1);
            s.erase(i,1);
        }

    }
}
int main()
{   

   string s = "(a+b)*(c)";
    // int index=0;
    stack<char> st;
    RedundantBrackets(s,st);
    
    cout<<s;

    // while(!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
}