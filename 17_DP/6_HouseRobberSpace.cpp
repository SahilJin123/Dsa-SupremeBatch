#include<iostream>
#include<bits/stdc++.h>
using namespace std ;


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


int SpaceOptimizedHouseRobber(vector<int> &nums,int n)
{
    int prev2 = 0;
    int prev1 = nums[0];
    // vector<int> dp(n+1,0);
    // dp[0] = nums[0];
    
    int curr = 0;
    for(int i =1;i<=n;i++)
    {
        int temp = 0;
        temp = prev2;
        int include = temp + nums[i];
        int exclude = prev1 + 0;
        curr = max(include,exclude);
        prev2 = prev1;
        prev1 = curr;
        
    }
    return prev1;
}


int main()
{
    vector<int> nums = {2,7,9,3,1};
    
    int ans = SpaceOptimizedHouseRobber(nums,nums.size()-1);

    cout<<"Answer is : "<<ans;
}