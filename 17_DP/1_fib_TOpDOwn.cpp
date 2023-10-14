#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

int topDownSolve(int n ,vector<int> &dp )
{
        // Base Case
        if(n==1 || n==0)
        {
            return n;
        }
        // Step 3: CHeck if ans already exists
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        // step 2: replace ans with dp[n]
        dp[n] = topDownSolve(n-1,dp) + topDownSolve(n-2,dp) ;

        return dp[n];
}
int main()
{
    // // Step1:- Create Dp array
        vector<int> dp(n+1,-1);
        int ans = topDownSolve(n,dp);
        return ans;
}