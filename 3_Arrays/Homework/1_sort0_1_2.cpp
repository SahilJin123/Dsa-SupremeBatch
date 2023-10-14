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
vector<int> sort(vector<int> arr)
{
    int start = 0;
    int end = arr.size()-1 ;
    int i =0; 
    
    while(end0>=i)
    {
        // cout<<"Iteration : "<<i<<endl;
        // cout<<"Start "<<start<<" End "<<end<<endl;
        if(arr[i]==0)
        {
            swap(arr[i],arr[start]);
            i++;
            start++;
        }
        else if(arr[i]==1)
        {
            i++;
        }
        else if(arr[i]==2)
        {
            swap(arr[i],arr[end]);
            end--;
        }

         
        // printarray(arr);
        // cout<<endl;
    }
    return arr;
}

int main()
{  
   vector<int> arr{0,1,0,1,1,0,0,2,1,0,2};
   
    arr = sort(arr);

   for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}