#include<iostream>
#include<bits/stdc++.h>
using namespace std ;


int binarySearch(int arr[],int s,int e,int key)
{
    int mid = s+ (e-s)/2;

    while(e>=s)
    {
        if(arr[mid]==key)
        {
            return mid;
        }else if(arr[mid]>key)
        {
            e = mid-1;
        }else{
            s = mid+1;
        }
        mid = s+ (e-s)/2;
    }

    return -1;
}

int exponential_Search(int arr[],int key)
{
    int i =0;
    int j = 1;
    while(arr[j]<=key)
    {  
        i=j;
        j*=2;
    }
    return binarySearch(arr,i,j,key);
}

int main()
{
    int arr[] = {3,4,5,6,11,13,14,15,56,70};

    int key = 13;

    // int size = sizeof(arr)/sizeof(arr[0]);

    int ans = exponential_Search(arr,key);

    cout<<ans;
}