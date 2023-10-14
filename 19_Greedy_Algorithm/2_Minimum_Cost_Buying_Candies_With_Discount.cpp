// Leetcode
// 2144. Minimum Cost of Buying Candies With Discount

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int buy = cost.size()-1;
        int free = cost.size()-3;

        int amount =0;
        int cnt = 2;
        while(buy>=0)
        {
            if(cnt==0)
            {
                cnt = 2;
                buy--;
            }else{
               amount +=cost[buy];
               buy--;
               cnt--;
            }
           
        }

        return amount;

    }
};