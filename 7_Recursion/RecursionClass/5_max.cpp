#include<iostream>
using namespace std ;

int maxi(int arr[],int size)
{
    
    if(size==1)
    return arr[0];
    
    // return max(arr[size-1],maxi(arr,size-1));
    if(arr[size-1]>maxi(arr,size-1))
    {
        return arr[size-1];
    }else{
        return maxi(arr,size-1);
    }
}
int main()
{
   int arr[] = {5,3,4,9,10};
   int size = sizeof(arr)/sizeof(arr[0]);
   int ans = maxi(arr,size);

   cout<<"Ans is:"<<ans;
}