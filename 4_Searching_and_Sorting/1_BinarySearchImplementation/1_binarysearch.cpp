#include<iostream>
#include<algorithm>
using namespace std ;
int binaryserach(int arr[],int size,int target)
{  
    int start = 0;
    int end = size - 1;
    // int mid = (start + end)/2;   //This can cause integer overflow bcz if s = 2^(31) - 1 and e=2^(31)-1 then computation of s+e can couse problem .  
    int mid = start + (end - start)/2 ;
    while (start<=end)
    {
        int element = arr[mid];
       if (element == target)
        {
            return mid;
        }
        else if(element > target)
        {
            // Search in left
            end = mid-1;
        }
        else{
            start = mid + 1;
        }
        
        mid = (start + end) / 2;
    }
    return -1;
    
}
int main()
{
   int arr[] = {2,3,4,5,6,7,8,9,12};
   int target = 12;
    int size = sizeof(arr);
    int indexoftarget = binaryserach(arr,size,target);
    if(indexoftarget == -1)
    {
        cout<<"Target not found";
    }else{
        cout<<"Target found at "<<indexoftarget ;
    }
}