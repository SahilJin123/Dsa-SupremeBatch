#include<iostream>
#include<bits/stdc++.h>
#include<vector>


using namespace std ;
int main()
{
     vector<int> arr{5,4,32,1,2};
     
    // outterloop -> (n-1) rounds
     for(int i=0;i<arr.size()-1;i++)
     {  
        int minIndex = i;
        // innerloop -> index of minimum element in range (i-n)
        for(int j =i+1;j<arr.size();j++)
        {
            if(arr[minIndex]>arr[j])
            {   
                // New Minimum than store
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
     }

     for(int i=0;i<arr.size();i++)
     {
        cout<<arr[i]<<" ";
     }
}