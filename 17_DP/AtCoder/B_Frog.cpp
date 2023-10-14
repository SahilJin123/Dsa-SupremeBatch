#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

int Solve(vector<int>& height,int i)
{
    if(i==0)
    return 0;

    int step1 = INT_MAX;
    int step2 = INT_MAX;
    if(i>0)
    step1 = abs(height[i]-height[i-1]) + Solve(height,i-1);

    if(i>1)
    step2 = abs(height[i]-height[i-2]) + Solve(height,i-2);

    int ans =  min(step1,step2);

    return ans;
}
int main()
{
    int n;
    cin>>n;

    vector<int> height(n);
    for(int i=0;i<n;i++)
    {
        cin>>height[i];
    }

    vector<int> dp(n+1,-1);
    int ans = Solve(height,n-1);
    cout<<ans;
}