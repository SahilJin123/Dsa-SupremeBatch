#include<iostream>
#include<vector>
using namespace std ;
int main()
{
  vector<int> arr{5,4,32,1,2};
  
  int n = arr.size(); 
  for(int round =0;round<n-1 ;round++)
  {  
    bool swapped = false; 
    for(int j =0;j<n-round-1 ;j++)
    {
        if(arr[j]>arr[j+1]) 
        {    
            swapped = true;
            swap(arr[j],arr[j+1]);
        }
    } 
    if(swapped==false)
    {
        break;      
    }
  }

   for(int i=0;i<arr.size();i++)
     {
        cout<<arr[i]<<" ";
     }
}