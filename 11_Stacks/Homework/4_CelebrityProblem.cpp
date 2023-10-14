#include<iostream>
#include<bits/stdc++.h>
using namespace std ;


int celebrity(vector<vector<int> >& M, int n) 
{
    // code here 
    stack<int> st;
    
    for(int i =0;i<n;i++)
    {
        st.push(i);
    }
    
    while(st.size()!=1)
    {
        int A = st.top();
        st.pop();
        int B = st.top();
        st.pop();
        
        if(M[A][B]==1)
        {
            st.push(B);
        }else{
            st.push(A);
        }
    }
    
    int MightBecelebrity = st.top();
    st.pop();
    for(int i=0;i<n;i++)
    {
        if(M[MightBecelebrity][i]!=0)
        {
            return -1;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if( i!=MightBecelebrity && M[i][MightBecelebrity]!=1)
        {
            return -1;
        }
    }
    
    return MightBecelebrity;
}
int main()
{

}