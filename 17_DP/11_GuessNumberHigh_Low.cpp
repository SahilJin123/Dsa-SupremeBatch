
#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

int SolveUsingRecursion(int start,int end)
{
    if(start>=end)
    {
        return 0;
    }

    int ans = INT_MAX;

    for(int i = start;i<=end;i++)
    {
        ans = min(ans,i + max(SolveUsingRecursion(start,i-1),SolveUsingRecursion(i+1,end))); 
    }

    return ans;
}
int getMoneyAmount(int n) {
    
    int ans = SolveUsingRecursion(1,n);
    return ans;
}
int main()
{
    cout<<getMoneyAmount(10);
}

