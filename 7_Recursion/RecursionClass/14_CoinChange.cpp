#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std ;
int solve(vector<int>& arr,int target,vector<int> output)
{   
    // Base Case
    if(target==0)
    {
        for(auto it:output)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return 0;
    }
    if(target <0)
    {
        return INT_MAX;
    }
    
    // lets solve 1 case
    int mini = INT_MAX;
    for(int i=0;i<arr.size();i++)
    {
       output.push_back(arr[i]);
       int ans = solve(arr,target-arr[i],output);
       output.pop_back();
       if(ans!=INT_MAX)
       mini = min(mini,ans+1);
    } 

    return mini; 
}
int main()
{
   vector<int> arr{1,2};
   int target = 5;
   vector<int>output;
   int ans = solve(arr,target,output);

   cout<<"Answer is: "<<ans;
}