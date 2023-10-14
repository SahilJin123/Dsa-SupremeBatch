#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std ;
 

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




int BottomUpcoinchange(vector<int>& coins,int amount)
{
    vector<int> dp(amount+1,INT_MAX);

    dp[0] = 0;
// dp[i] :- yeh darshata hai ki i amount banane ke liye minimum kitne coins chahiye
    for (int i = 1; i<=amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {   
           if(i-coins[j] >=0 && dp[i-coins[j]]!=INT_MAX)
           {
             int ans = dp[i-coins[j]];
             dp[i] = min(ans+1,dp[i]);
           }
        }
        
    }

    return dp[amount];
    
}

int main()
{
    vector<int> coins = {1,2,5};
    int amount = 13;


    // vector<int> dp(amount+1,-1);

    // int ans =  TopDowncoinchange(coins,amount,dp);
    //  if(ans == INT_MAX)
    // {
    //     ans = -1;
    // }
    // cout<<"Answer is: "<<ans<<endl;    

    
    int ans =  BottomUpcoinchange(coins,amount);
     if(ans == INT_MAX)
    {
        ans = -1;
    }
    cout<<"Answer is: "<<ans<<endl;    





}