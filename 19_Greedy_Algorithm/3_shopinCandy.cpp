//  Gfg Shop in Candy Store


#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int prices[] = {2,8,6,9,4,7};
    int n = 6;

    sort(prices,prices+n);

    int amount = 0;
    int buy = 0;

    int free = n-1;

    while(buy<=free)
    {
        amount += prices[buy];
        buy++;
        free = free -2;
    }

    cout<<amount;
}