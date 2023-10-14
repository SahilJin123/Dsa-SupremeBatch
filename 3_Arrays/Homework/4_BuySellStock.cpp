#include<iostream>
#include<vector>
#include<limits.h>
using namespace std ;

int solve(vector<int>prices)
{
    int MinSofar = INT_MAX;
    int maxProfit = INT_MIN;
    for(int i=0;i<prices.size();i++)
    {
        if(MinSofar>prices[i])
        {
            MinSofar = prices[i];
        }
        if(maxProfit<prices[i] - MinSofar)
        {
            maxProfit = prices[i] - MinSofar;
        }
    }

    return maxProfit;
}
int main()
{
    vector<int>prices{3,1,4,8,7,2,5};

    int ans = solve(prices);

    cout<<ans;
}