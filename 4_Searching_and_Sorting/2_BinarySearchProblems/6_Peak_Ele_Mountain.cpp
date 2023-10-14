#include<iostream>
using namespace std ;
int PeakInMountain(int arr[],int size)
{
    int s =0;
    int e = size -1;
    int mid = s+ (e-s)/2 ;
    int ans = -1;
    while (e>s)
    {
        if(arr[mid+1]>arr[mid])
        {
            s = mid + 1;
        }else 
        {
            e = mid;
        }
        
        mid = s + (e-s)/2;
    }
    return arr[s];
}
int main()
{
    int arr[] ={0,10,5,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int ans = PeakInMountain(arr,size);
    cout << ans;
}