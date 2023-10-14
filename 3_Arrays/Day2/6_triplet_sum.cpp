#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    vector<int> arr{0,10,20,40,60,70};
    int sum = 60;
    for(int i =0;i<arr.size();i++)
    {   
        int element1 = arr[i];
        for (int j= i +1; j < arr.size(); j++)
        {    
            int element2 = arr[j];
            for (int k = j+1; k < arr.size(); k++)
            {
            int add = element1 + element2 + arr[k];
            if(sum==add)
            {
                cout<<"("<<arr[i]<<" , "<<arr[j]<<","<<arr[k]<<")"<<endl;
            }
            }
            
        }
        
    }
}