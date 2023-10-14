#include<bits/stdc++.h>
using namespace std ;
int pivot_index(vector<int> arr)
{
    int s =0;
    int e = arr.size()-1;
    int mid = s + (e-s)/2 ;
    while (e>=s)
    {
        if(mid+1 <arr.size() && arr[mid]>arr[mid+1])
        {
            return mid;
        }else if(mid-1 >=0 && arr[mid]<arr[mid-1]){
            return mid-1 ;
        }

        if(arr[s]>arr[mid])
        {   
            // Left Search karna
            e = mid -1;
        }
        if(arr[s]<arr[mid])
        {
            // Right Search 
            s = mid +1 ;
        }
         mid = s + (e-s)/2 ; 
    }
    return -1; 
}
int main()
{
   vector<int> v{3,4,5,6,7,1,2};
   int ans = pivot_index(v);
   cout<<"Pivot Index :"<<ans<<endl;
   cout<<"Pivot Element :"<<v[ans];
}