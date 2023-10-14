#include<iostream>
#include<vector>
using namespace std ;
int oddoccurence(vector<int> arr)
{
    int s =0;
    int e = arr.size()-1;
    int mid = s + (e-s)/2;

    while (e>=s)
    {
        if(s==e)
        {
            return s;
        }
        if(mid%2==0)
        {
            // even index

            if(mid+1<arr.size() && arr[mid]==arr[mid+1])
            {
                s=mid+2;
            }else{
                e = mid-2;
            }
        }
        else{
            // odd index

            if( mid-1>=0 && arr[mid-1]==arr[mid])
            {
                s=mid+1;
            }else{
                e = mid-1;
            }
        }
        mid = s + (e-s)/2;
    }
    
    return -1;
}

int main()
{
    vector<int> arr{1,1,3,3,2,2,4,4,5,5,2,2,3,1,1,600,600,4,4};
    int ans = oddoccurence(arr);
    cout<<"Index: "<<ans<<endl;
    cout<<"Value: "<<arr[ans];
}