#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

bool isPossible(long long arr[],long long treeCount,long long chopingMetre,long long mid)
{
    long long sum = 0;

    for(long long i=0;i<treeCount;i++)
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

long long EKO(long long arr[],long long treeCount,long long chopingMetre)
{
    sort(arr,arr+treeCount);

    long long s = 1;
    long long e = arr[treeCount-1];
    long long mid = s+(e-s)/2 ; 
    long long H = 1;
    while(s<=e)
    {
        if(isPossible(arr,treeCount,chopingMetre,mid))
        {
            H=mid;
            s=mid+1;
        }else{
            e = mid-1;
        }
        mid = s+(e-s)/2 ; 
    }
    return H;
}
int main()
{
    long long chopingMetre;
    // long long H;
    long long treeCount;
    cin>>treeCount>>chopingMetre;
    long long arr[treeCount];

    for(long long i=0;i<treeCount;i++)
    {
        cin>>arr[i];
    }

    cout<<EKO(arr,treeCount,chopingMetre);
}