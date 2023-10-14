#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

int findUnique( vector<int> arr)
{   
    int ans = 0;
    for(int i =0;i<arr.size();i++)
    {
        ans = ans^arr[i];
    }
    return ans;
}
int main()
{
    int n ;
    cout<<"Enter the Size of array :"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<endl;
    cout<<"Enter the Elements of array :"<<endl;
    for(int i =0;i<arr.size();i++)
    {
        cin>>arr[i];
    }

    int uniqueElement = findUnique(arr);

    cout<<"Unique element is :"<<uniqueElement<<endl;
}