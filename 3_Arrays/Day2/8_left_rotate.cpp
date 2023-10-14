#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    vector<int>arr{10,20,30,4,5,6,7};
    int k = 3;
    
    for(int i =0;i<k;i++)
    {
    int element = arr[0];
    for(int i =0;i<arr.size()-1;i++)
    {
        arr[i]=arr[i+1];
    }

    arr[arr.size()-1] = element;
    }
    
     for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}


// cout<<"Start: "<<start<<" End: "<<end<<" Value of i: "<<i<<endl;
            // printarray(arr);



            void printarray(vector<int> arr)
{
       for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}