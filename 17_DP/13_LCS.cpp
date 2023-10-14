// class Solution {
// public:
//     int solve(string a, string b,int i,int j)
//     {
//         if(i==a.length() || j==b.length())
//         {
//             return 0;
//         }

//         int ans = 0;
//         if(a[i]==b[j])
//         {
//             ans = solve(a,b,i+1,j+1) + 1; 
//         }else{
//             ans = max(solve(a,b,i,j+1),solve(a,b,i+1,j)) + 0;
//         }

//         return ans; 
//     }
//     int solveMemo(string& a,string& b,int i,int j,vector<vector<int>>& dp)
//     {
//         if(i==a.length() || j==b.length())
//         {
//             return 0;
//         }

//         if(dp[i][j]!=-1)
//         {
//             return dp[i][j];
//         }
//         int ans = 0;
//         if(a[i]==b[j])
//         {
//             ans = solveMemo(a,b,i+1,j+1,dp) + 1; 
//         }else{
//             ans = max(solveMemo(a,b,i,j+1,dp),solveMemo(a,b,i+1,j,dp)) + 0;
//         }

//         return dp[i][j] = ans; 
//     }

//     int solveTab(string& a,string& b)
//     {
//         int sizea = a.length();
//         int sizeb = b.length();
//         vector<vector<int>> dp(sizea+2,vector<int>(sizeb+2,0));

//         for(int i = sizea-1;i>=0;i--)
//         {
//             for(int j = sizeb-1;j>=0;j--)
//             {
//                 int ans = 0;
//                 if(a[i]==b[j])
//                 {
//                     ans = dp[i+1][j+1] + 1;
//                 }else{
//                     ans = max(dp[i+1][j],dp[i][j+1]) + 0;
//                 }

//                 dp[i][j] = ans; 
//             }
//         }

//         return dp[0][0];

//     }

//     int solveSO(string& a,string& b)
//     {
//         int sizea = a.length();
//         int sizeb = b.length();
//         // vector<vector<int>> dp(sizea+2,vector<int>(sizeb+2,0));
//         vector<int> curr(sizeb+1,0);
//         vector<int> next(sizeb+1,0);

//         for(int i = sizea-1;i>=0;i--)
//         {
//             for(int j = sizeb-1;j>=0;j--)
//             {
//                 int ans = 0;
//                 if(a[i]==b[j])
//                 {
//                     ans = next[j+1]+ 1;
//                 }else{
//                     ans = max(curr[j+1],next[j]) + 0;
//                 }

//                 curr[j] = ans; 
//             }

//             next = curr;
//         }

//         return next[0];

//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int i = 0;
//         int j =0;
//         // vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1));
//         // return solveMemo(text1,text2,i,j,dp);  

//         return solveSO(text1,text2); 
//     }
// };


#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    vector<vector<int>> envelopes{{5,4},{6,4},{6,7},{2,3}};
    sort(envelopes.begin(),envelopes.end());
    for (int i = 0; i<envelopes.size();i++)
    {
        for (int j = 0;j<envelopes[i].size();j++)
        {
            cout<<envelopes[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<envelopes[1][0]<<envelopes[0][0]<<envelopes[1][1]<<envelopes[0][1];
}