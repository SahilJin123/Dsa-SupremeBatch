#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{  
    vector<int>arr{7,6,4,3,1};
    int initial =0;
    for(int i =0;i<arr.size();i++)
    {
        for(int j = i+1 ;j<arr.size();j++)
        {
            int profit = arr[j] - arr[i];
            if(profit>initial)
            {
                initial = profit;
            }
        }
    }
    cout<<initial;
}