#include<iostream>
using namespace std ;

int binarysearch(int arr[],int& size,int& start,int& end,int& key)
{
      if(start>end)
      return -1;
      
      int mid = start + (end-start)/2;

      if(arr[mid]==key)
      return mid;



      if(arr[mid]>key)
      {
         //   left search
        int e = mid-1;
        return binarysearch(arr,size,start,e,key);
      }
      else
      {
        int s = mid+1;
        return binarysearch(arr,size,s,end,key);
      }


}
int main()
{
   int arr[] = {10,20,20,30,40,50,60};

   int size = sizeof(arr)/sizeof(arr[0]);
   int start =0;
   int end = size-1;
   int key = 40;
   int ans = binarysearch(arr,size,start,end,key);
    cout<<"Answer is:"<<ans;
}