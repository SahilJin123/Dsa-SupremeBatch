#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

// ChopingMetre :- Kitni Wood metre hume chahiye 
// TotalTree :- Total Kitne trees hai ek row main
bool isPossible(long long arr[],long long TotalTree,long long chopingMetre,long long mid)
{
    long long sum = 0;

    for(long long i=0;i<TotalTree;i++)
    {
        if(arr[i]>=mid)
        {
            sum+=(arr[i]-mid);
        }
    }

    if(sum>=chopingMetre)
    return true;

    return false;
}

long long EKO(long long arr[],long long TotalTree,long long chopingMetre)
{
    sort(arr,arr+TotalTree);

    long long s = 1;
    long long e = arr[TotalTree-1];
    long long mid = s+(e-s)/2 ; 
    long long HeightSawBlade = 1;
    while(s<=e)
    {
        if(isPossible(arr,TotalTree,chopingMetre,mid))
        {
            HeightSawBlade=mid;
            s=mid+1;
        }else{
            e = mid-1;
        }
        mid = s+(e-s)/2 ; 
    }
    return HeightSawBlade;
}
int main()
{
    long long chopingMetre;
    // long long H;
    long long TotalTree;
    cin>>TotalTree>>chopingMetre;
    long long arr[TotalTree];

    for(long long i=0;i<TotalTree;i++)
    {
        cin>>arr[i];
    }

    cout<<EKO(arr,TotalTree,chopingMetre);
}