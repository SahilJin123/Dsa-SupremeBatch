#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std ;

int coinchange(vector<int>& coins,int amount)
{
    if(amount==0)
    {
        return 0;
    }

    if(amount<0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        int ans = coinchange(coins,amount - coins[i]);
        if(ans!=INT_MAX)
        mini = min(ans+1,mini);
    }
    return mini;
    
}

int TopDowncoinchange(vector<int>& coins,int amount,vector<int> &dp)
{
    if(amount==0)
    {
        return 0;
    }

    if(amount<0)
    {
        return INT_MAX;
    }

    if(dp[amount]!=-1)
    {
        return dp[amount];
    }

    int mini = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
       int ans = TopDowncoinchange(coins,amount - coins[i],dp);
       if(ans!=INT_MAX)
       mini = min(ans+1,mini);
    }

    dp[amount] = mini;
    return mini;
    
}

int main()
{
    vector<int> coins = {1,2,5};
    int amount = 11;

    // int ans = coinchange(coins,amount);
    // if(ans == INT_MAX)
    // {
    //     ans = -1;
    // }
    // cout<<"Answer is: "<<ans<<endl;

    vector<int> dp(amount+1,-1);

    int ans =  TopDowncoinchange(coins,amount,dp);
     if(ans == INT_MAX)
    {
        ans = -1;
    }
    cout<<"Answer is: "<<ans<<endl;    




}