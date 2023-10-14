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
vector<int> mov_neg_left(vector<int> arr)
{
    int start = 0;
    int end = arr.size()-1 ;
    
    while(end>=start)
    {
        if(arr[start]<0)
        {
            start++;
        }else if(arr[end]>0)
        {
            end--;
        }else{
            swap(arr[start],arr[end]);
        }
    }
    
    
    return arr;
}

int main()
{  
   vector<int> arr{1,2,-3,4,-5,6};
   
    arr = mov_neg_left(arr);

   for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}