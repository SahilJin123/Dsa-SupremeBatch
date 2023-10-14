#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    vector<int> arr{0,0,1,1,0,1,0,0,1,0,0};
    
    int start = 0;

    for(int i =0;i<arr.size();i++)
    {
        if(arr[i]==0)
        {
            swap(arr[start],arr[i]);
            start++;
        }
    }
    
   for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
     
}
