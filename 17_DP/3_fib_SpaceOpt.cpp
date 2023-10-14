#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

int SpaceOptiimizedSolve(int n)
{
    int prev1 = 0;
    int prev2= 1;
    if(n==0)
    return prev1;

    if(n==1)
    return prev2;

    int ans;
    for(int i=2;i<=n;i++)
    {
        ans = prev1 + prev2 ;
        prev1 = prev2;
        prev2 = ans;
    }

    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<SpaceOptiimizedSolve(n);
}