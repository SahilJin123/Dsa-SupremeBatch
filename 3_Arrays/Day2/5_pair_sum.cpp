#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    vector<int> arr{0,10,20,40,60,70};
    int sum = 60;
    for(int i =0;i<arr.size();i++)
    {   
        int element = arr[i];
        for (int j= i +1; j < arr.size(); j++)
        {
            int add = element + arr[j];
            if(sum==add)
            {
                cout<<"("<<arr[i]<<" , "<<arr[j]<<")"<<endl;
            }
        }
        
    }
}