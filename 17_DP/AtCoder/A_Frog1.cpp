#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<limits.h>
using namespace std;

int Solve(vector<int>& height,int i,int cost)
{
    // cout<<"Cost when Stone is "<< i <<" :"<<cost<<endl;
    if(i>=height.size()-1)
    {
        return cost;   
    }

    int step1 = INT_MAX;
    int step2 = INT_MAX;
    if(i+1<height.size())
    {
        cost+=abs(height[i+1]-height[i]);
        step1 = Solve(height,i+1,cost);
    }

    cost-=abs(height[i+1]-height[i]);

    if(i+2<height.size())
    {
        cost+=abs(height[i+2]-height[i]);
        // cout<<"Cost when index is "<< i+1<<" :"<<cost<<endl;
        step2 = Solve(height,i+2,cost);
    }
    

    int ans = min(step1,step2);
    // cout<<"Ans at index "<<i<<" is "<<ans<<endl;
    return ans;
}

int SolveMemo(vector<int>& height,int i,int cost,vector<int>& dp)
{
    int n = height.size();
    if(i==n-1)
    {
        return cost;   
    }

    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int step1 =  INT_MAX;
    int step2 = INT_MAX;
    if(i+1<n)
    {
        cost+=abs(height[i+1]-height[i]);
        step1 = SolveMemo(height,i+1,cost,dp);
    }

    cost-=abs(height[i+1]-height[i]);
    
    if(i+2<n)
    {
        cost+=abs(height[i+2]-height[i]);
        step2 = SolveMemo(height,i+2,cost,dp);
    }
    

    dp[i] = min(step1,step2);
    return dp[i];
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
    int cost = 0;
    vector<int> dp(n+1,-1);
    int ans = SolveMemo(height,0,cost,dp);
    cout<<ans;
}

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> height(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> height[i];
//     }

//     vector<int> dp(n, 0);
//     dp[1] = abs(height[1] - height[0]);

//     for (int i = 2; i < n; i++)
//     {
//         int step1 = dp[i - 1] + abs(height[i] - height[i - 1]);
//         int step2 = dp[i - 2] + abs(height[i] - height[i - 2]);
//         dp[i] = min(step1, step2);
//     }

//     cout << dp[n - 1];
//     return 0;
// }
