#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

int HouseRobber(vector<int> &nums,int index,int amount)
{
    if(index>=nums.size())
    {
        return amount;
    }

    int include = HouseRobber(nums,index+2,amount+nums[index]);
    int exclude = HouseRobber(nums,index + 1,amount);

    int maxi = max(include,exclude);

    return maxi;
}


int TopDownHouseRobber(vector<int> &nums,int index,int amount,vector<int> &dp)
{
    if(index>=nums.size())
    {
        return amount;
    }

    if(dp[index]!=-1)
    {
        return dp[index];
    }

    
    int include = TopDownHouseRobber(nums,index+2,amount+nums[index],dp);
    int exclude = TopDownHouseRobber(nums,index + 1,amount,dp);

    dp[index] = max(include,exclude);

    return dp[index];
}

int BottomUpHouseRobber(vector<int> &nums,int n)
{
    vector<int> dp(n+1,0);
    dp[0] = nums[0];

    for(int i =1;i<=n;i++)
    {
        int temp = 0;
        if(i-2>=0)
        {
            temp = dp[i-2];
        }
        int include = temp + nums[i];
        int exclude = dp[i-1] + 0;
        dp[i] = max(include,exclude);
        
    }
    return dp[n];

}

int main()
{
    vector<int> nums = {2,7,9,3,1};
    int index = 0;
    int amount = 0;

    // int ans = HouseRobber(nums,0,0);

    // cout<<"Answer is : "<<ans;

    
    vector<int> dp(nums.size(),-1);
    
    int ans = TopDownHouseRobber(nums,0,0,dp);

    cout<<"Answer is : "<<ans;
}