#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
const int mod = 1000000007;

int SolveusingRecurssion(int n ,int k)
{
    if(n==1)
    {
        return k;
    }

    if(n==2)
    {
        return (k + k*(k-1));
    }
    int ans = (SolveusingRecurssion(n-2,k) + SolveusingRecurssion(n-1,k))*(k-1);

    return ans;
}

long long TopDown(int n ,int k,vector<long long> &dp)
{
    if(n==1)
    {
        return k;
    }

    if(n==2)
    {
        return (k + k*(k-1));
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    // dp[n] = (TopDown(n-2,k,dp) + TopDown(n-1,k,dp))*(k-1);
    dp[n] = ((TopDown(n-2,k,dp)%mod*(k-1))%mod + (TopDown(n-1,k,dp)%mod*(k-1))%mod)%mod;


    return dp[n];
}


long long BottomUp(int n ,int k)
{

    vector<long long> dp(n+1,-1);
    dp[1] = k;
    dp[2] =  (k + k*(k-1));


    for (int i = 3; i<=n; i++)
    {
        dp[i] = (dp[i-2]+dp[i-1])*(k-1);
    }
    

    return dp[n];
}

long long SpaceOptimized(int n ,int k)
{
    int prev2= k;
    int prev1 =  (k + k*(k-1));

     int curr = 0;
    for (int i = 3; i<=n; i++)
    {
       curr = (prev2+prev1)*(k-1);

    //    Yaha hi galati karunga
       prev2 = prev1;
       prev1 = curr;
    }
    return curr;
}
int main()
{
    int n = 4;
    int k = 3;

    // int ans = SolveusingRecurssion(n,k);


    // vector<long long> dp(n+1,-1);

    // int ans = TopDown(n,k,dp);



    // long long ans = BottomUp(n,k);


    long long ans = SpaceOptimized(n,k);
    cout<<"Answer is: "<<ans;
} 