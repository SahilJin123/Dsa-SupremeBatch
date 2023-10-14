#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
   vector<int> arr{1,2,3,3,3,4,6,8}; 
   vector<int> brr{3,3,4,7,9};

   vector<int> ans;

   for(int i =0;i<arr.size();i++)
   {
    for (int j = 0; j < brr.size(); j++)
    {
        if(arr[i]==brr[j])
        {   
            brr[j] = INT16_MIN;
            ans.push_back(arr[i]);
            arr[i] = INT16_MIN;
        }
    }
    
   } 

   for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}