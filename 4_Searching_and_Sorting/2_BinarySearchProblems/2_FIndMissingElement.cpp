#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std ;
// ************************************************************Method -1(Binary Search when array is sorted)**********************************************************************
int findMissingelement(vector<int>arr)
{
    int s =0;
    int e = arr.size()-1;
    int mid = s +(e-s)/2 ;
    int ans =0;
    while (e>=s)
    {
        if(arr[mid]==mid+2)
        {
            ans = arr[mid] -1;
            e = mid-1;
        }
        else 
        {
            s = mid+1;
        }
        mid = s +(e-s)/2 ;
    }

    return ans;
    
}
// ************************************************************Method -2(Hash Map when array is sorted or not sorted)*************************************************************

// int findMissingelement(vector<int>arr)
// {
//     vector<int>hash(arr.size()+1,0);

//     for(int i=0;i<arr.size();i++)
//     {
//         hash[arr[i]]++;
//     }

//     for(int i=0;i<hash.size();i++)
//     {
//         if(i!=0 && hash[i]==0)
//         {
//             return i;
//         }
//     }


// }
int main()
{
     vector<int>arr = {1,3,4,5,6,7,8,9};
     int ans = findMissingelement(arr);
     cout<<ans;
}

