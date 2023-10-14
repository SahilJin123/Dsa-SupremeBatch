#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std ;
void solve(vector<int>& arr)
{
  int i=0;
  int j=0;

  while (i<arr.size())
  {
    if(arr[i]<0)
    {
      swap(arr[i],arr[j]); 
      i++;
      j++;
    }else{
      i++;
    }
  }
  
}
int main()
{
  vector<int> arr{1,2,-3,4,-1,-6,4,7};
  solve(arr);

  for(auto it:arr)
  {
    cout<<it<<" ";
  }
}