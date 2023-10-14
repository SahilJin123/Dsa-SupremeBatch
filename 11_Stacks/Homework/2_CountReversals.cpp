#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

int countRev (string s)
{
    // your code here
    if(s.length()%2==0)
    {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(!st.empty() && s[i]=='}' && st.top()=='{')
            {
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        
        int count =0;
        while (!st.empty())
        {
            char temp1 = st.top();
            st.pop();
            char temp2 = st.top();
            st.pop();

            if(temp1==temp2)
            {
                count+=1;
            }else{
                count+=2;
            }
        }
        return count;
    }
    
    return -1;
}
int main()
{
    string s = "}{{}}{{";
    cout<<countRev(s);
}