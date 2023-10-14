#include<iostream>
#include<vector>
using namespace std ;

void printSubarray_util(vector<int>& arr,int start,int end)
{
   if(arr.size()<=end)
   return;

   int i=start;
   int j =end;
   for(i;i<=j;i++)
   {
    cout<<arr[i]<<" ";
   }
   cout<<endl; 
   
   printSubarray_util(arr,start,end+1);

//    printSubarray_util(arr,start+1,start+1);

}
void printSubarray(vector<int>& arr)
{
    for(int start=0;start<arr.size();start++)
    {
        printSubarray_util(arr,start,start);
    }
}

int main()
{
   vector<int>arr{1,2,3,4,5,6};
//    int start =0;
//    int end = arr.size() - 1;
//    vector<vector<int>>ans;

   printSubarray(arr);
}