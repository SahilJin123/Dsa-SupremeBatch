class Solution {
public:
    bool solveUsingRecursion(int index, vector<int>& nums, int target) {
        //base case
        int n = nums.size();
        if(index >= n)
            return 0;

        if(target < 0)
            return 0;

        if(target == 0) 
            return 1;

        bool include = solveUsingRecursion(index+1, nums, target-nums[index]);
        bool exclude = solveUsingRecursion(index+1, nums, target);

        return (include || exclude);
    }

    bool solveUsingMem(int index, vector<int>& nums, int target, vector<vector<int> >& dp) {
        //base case
        int n = nums.size();
        if(index >= n)
            return 0;

        if(target < 0)
            return 0;

        if(target == 0) 
            return 1;

        if(dp[index][target] != -1)
            return dp[index][target];

        bool include = solveUsingMem(index+1, nums, target-nums[index], dp);
        bool exclude = solveUsingMem(index+1, nums, target, dp);

        dp[index][target] = (include || exclude);
        return dp[index][target];
    }
    bool SolveUsingTabulation(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<vector<int> > dp(nums.size()+1, vector<int>(target+1, 0));

        for(int i=0;i<nums.size();i++)
        {
            dp[i][0] = 1;
        }

        for(int i = n-1;i>=0;i--)
        {
            for(int t=1 ;target>=t;t++)
            {
                bool include = 0;
                if(t-nums[i]>=0)
                include = dp[i+1][t-nums[i]];

                bool exclude = dp[i+1][t];

                dp[i][t] = (include || exclude);
            }
        }
        return dp[0][target];
    }

     bool SolveUsingSpaceOptimization(vector<int>& nums, int target)
    {
        int n = nums.size();
        
        vector<int> curr(target+1,0);
        vector<int> next(target+1,0);

        next[0] = 1;

        for(int i = n-1;i>=0;i--)
        {
            for(int t=1 ;target>=t;t++)
            {
                bool include = 0;
                if(t-nums[i]>=0)
                include = next[t-nums[i]];

                bool exclude = next[t];

                curr[t] = (include || exclude);
            }

            //    shift
              next = curr;
        }

        return curr[target];

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }
        //yha hi galti karunga
        if(sum & 1)
            return false;
        int target = sum/2;
        int index = 0;
        // bool ans = solveUsingRecursion(index, nums, target);

        // vector<vector<int> > dp(nums.size(), vector<int>(target+1, -1));
        // bool ans = solveUsingMem(index, nums, target, dp);


        // bool ans = SolveUsingTabulation(nums, target);
        // return ans;


        bool ans = SolveUsingSpaceOptimization(nums, target);
        return ans;
    }
};


// bool canPartition(vector<int>& nums) {
    
//     if(nums.size()==1)
//     {
//         return false;
//     }
//     int i =0 ;
//     int j = nums.size()-1;
//     sort(nums.begin(),nums.end());
//     int sum1 = nums[i];
//     int sum2 = nums[j];
//     while((j-i)!=1)
//     {
//         if(sum2>sum1)
//         {
//             i++;
//             sum1+=nums[i];
//         }else if(sum1>sum2)
//         {
//             j--;
//             sum2+=nums[j];
//         }else if(sum1==sum2 && (j-i)!=1)
//         {
//             return false;
//         }
//     }

//     if(sum1==sum2)
//     {
//         return true;
//     }else{
//         return false;
//     }
// }

