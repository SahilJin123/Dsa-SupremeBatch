class Solution {
public:
    int LCS(string a, string b,int i,int j)
    {
        if(i==a.length() || j==b.length())
        {
            return 0;
        }

        int ans = 0;
        if(a[i]==b[j])
        {
            ans = LCS(a,b,i+1,j+1) + 1; 
        }else{
            ans = max(LCS(a,b,i,j+1),LCS(a,b,i+1,j)) + 0;
        }

        return ans; 
    }
    int LCSMemo(string& a,string& b,int i,int j,vector<vector<int>>& dp)
    {
        if(i==a.length() || j==b.length())
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans = 0;
        if(a[i]==b[j])
        {
            ans = LCSMemo(a,b,i+1,j+1,dp) + 1; 
        }else{
            ans = max(LCSMemo(a,b,i,j+1,dp),LCSMemo(a,b,i+1,j,dp)) + 0;
        }

        return dp[i][j] = ans; 
    }

    int LCStab(string& a,string& b)
    {
        int sizea = a.length();
        int sizeb = b.length();
        vector<vector<int>> dp(sizea+2,vector<int>(sizeb+2,0));

        for(int i = sizea-1;i>=0;i--)
        {
            for(int j = sizeb-1;j>=0;j--)
            {
                int ans = 0;
                if(a[i]==b[j])
                {
                    ans = dp[i+1][j+1] + 1;
                }else{
                    ans = max(dp[i+1][j],dp[i][j+1]) + 0;
                }

                dp[i][j] = ans; 
            }
        }

        return dp[0][0];

    }

    int LCSso(string& a,string& b)
    {
        int sizea = a.length();
        int sizeb = b.length();
        // vector<vector<int>> dp(sizea+2,vector<int>(sizeb+2,0));
        vector<int> curr(sizeb+1,0);
        vector<int> next(sizeb+1,0);

        for(int i = sizea-1;i>=0;i--)
        {
            for(int j = sizeb-1;j>=0;j--)
            {
                int ans = 0;
                if(a[i]==b[j])
                {
                    ans = next[j+1]+ 1;
                }else{
                    ans = max(curr[j+1],next[j]) + 0;
                }

                curr[j] = ans; 
            }

            next = curr;
        }

        return next[0];

    }
    int longestPalindromeSubseq(string s) {
        
        string first = s;
        reverse(s.begin(),s.end());
        string second = s;
        return LCSso(first,second);
    }
};