#include<iostream>
#include<vector>
#include<limits.h>
using namespace std ;

void solve(vector<int>prices,int index,int& minPriceSoFar,int& maxProfit)
{
//    Base case
    
    if(index==prices.size())
    return;
    
// ek case solve kardo
    minPriceSoFar = min(prices[index],minPriceSoFar);

    maxProfit = max(maxProfit,prices[index]-minPriceSoFar);
    
    // Baaki recursion Sambhal lega
   solve(prices,index+1,minPriceSoFar,maxProfit);


}
int main()
{
    vector<int>prices{7,1,5,3,6,4};
    
    int index =0;
    int maxProfit = INT_MIN;
    int minPriceSoFar = INT_MAX;
    solve(prices,index,minPriceSoFar,maxProfit);

    cout<<maxProfit;
}