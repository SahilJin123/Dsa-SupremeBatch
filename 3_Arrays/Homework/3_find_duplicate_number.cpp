#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

void printarray(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}

// int findDuplicate(vector<int>& nums) {  

//         sort(nums.begin(),nums.end());

//         for(int i=0;i<nums.size();i++)
//         {
//             int element = nums[i];

//             if(nums[i+1]==element)
//             {
//                 return element;
//             }
//         }
        
// }


//***************************************** Partitioning Method *********************************************
int findDuplicate(vector<int>& nums){ 

int index =0;

for(int i=0;i<nums.size()-1;i++)
{
    swap(nums[index],nums[nums[index]]);
}
return nums[index];
}
int main()
{  
   vector<int> arr{3,1,3,4,2,3};
   
    int ans = findDuplicate(arr);

     cout<<ans;
    
}
