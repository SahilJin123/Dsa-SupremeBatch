#include<iostream>
#include<vector>
#include<limits.h>
using namespace std ;

int rob(vector<int>& nums) {
        int maxProfit = INT_MIN;

        for(int i=0;i<nums.size();i++)
        {   
            int temp =0;
            for(int j =i;j<nums.size();j++)
            {
                temp+=nums[j];
                j++;
            }
            if(temp>maxProfit)
            {
                maxProfit = temp;
            }
        }

        return maxProfit;
}
int main()
{
    vector<int>nums{1,2,3,1};

    int ans = rob(nums);

    cout<<ans;
}