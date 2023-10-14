// ******************************************************************Leetcode = 41***************************************************************************
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std ;

int MissingElement(vector<int> arr)
{
    int len = arr.size() + 2;
    vector<int> temp(len,0);

    for(int i =0;i<arr.size();i++)
    {   
        if(len>=arr[i])
        temp[arr[i]]++;
    }

    for(int i =0;i<temp.size();i++)
    {   
        if(i!=0 && temp[i]==0)
        return i;
    }
}
int main()
{
    vector<int> arr{2,1};
    int ans = MissingElement(arr);
    cout<<ans;
}