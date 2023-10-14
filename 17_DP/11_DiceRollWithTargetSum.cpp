class Solution {
public:
    long long int Mod = 1000000007;
    int SolveUsingRecursion(int n, int k, int target)
    {
        if(n==0)
        {
            if(target==0)
            {
                return 1;
            }else{
                return 0;
            }
        }

        int ans = 0;

        for(int i =1;i<=k;i++)
        {
            ans += SolveUsingRecursion(n-1,k,target-i);
        }

        return ans;
    }

    long long int SolveUsingMem(long long int n, long long int k, long long int target,vector<vector<long long int>>& dp)
    {
        if(n==0)
        {
            if(target==0)
            {
                return 1;
            }else{
                return 0;
            }
        }

        if(n!=0 && target==0)
        {
            return 0;
        }

        if(dp[n][target]!=-1)
        {
            return dp[n][target];
        }

        long long int ans = 0;

        for(int i =1;i<=k;i++)
        {
            long long int recans = 0;
            if(target-i>=0)
            {
                recans = SolveUsingMem(n-1,k,target-i,dp);
            }
            ans = (ans % Mod +recans % Mod) % Mod;
        }

        dp[n][target] = ans;
        return dp[n][target];
    }
    
    long long int Tabulation(int n, int k, int target)
    {
        vector<vector<long long int>> dp(n+1,vector<long long int>(target+1,0));

        dp[0][0] = 1;

        for(int index = 1;index<=n;index++)
        {
            for(int t = 1;t<=target;t++)
            {
                long long int ans = 0;
                for(int i =1;i<=k;i++)
                {
                    long long int recans = 0;
                    if(t-i>=0)
                    {
                        recans = dp[index-1][t-i];
                    }
                    ans = (ans % Mod +recans % Mod) % Mod;
                }
                dp[index][t] = ans;
            }
        }

        return dp[n][target];
    }

    long long int SpaceOptimization(int n, int k, int target)
    {
        // vector<vector<long long int>> dp(n+1,vector<long long int>(target+1,0));

        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
        prev[0] = 1;

        for(int index = 1;index<=n;index++)
        {
            for(int t = 1;t<=target;t++)
            {
                long long int ans = 0;
                for(int i =1;i<=k;i++)
                {
                    long long int recans = 0;
                    if(t-i>=0)
                    {
                        recans = prev[t-i];
                    }
                    ans = (ans % Mod +recans % Mod) % Mod;
                }
                curr[t] = ans;
            }
            // Shift
            prev = curr;
        }

        return curr[target];
    }


    int numRollsToTarget(int n, int k, int target) {
        
        // return SolveUsingRecursion(n,k,target,dp);

        // vector<vector<long long int>> dp(n+1,vector<long long int>(target+1,-1));
        // return SolveUsingMem(n,k,target,dp);

        // return Tabulation(n,k,target);

        return SpaceOptimization(n,k,target);
    }
};