#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std ;
int main()
{
    int arr[] = {1,7,9,3,5};
    int sizea =5; 
    int brr[] = {3,3,5,5,6,8};
    int sizeb = 6;
    vector<int> ans;

    for(int i=0;i<sizea;i++)
    {
        ans.push_back(arr[i]);
    }

    for(int i=0;i<sizeb;i++)
    {
        ans.push_back(brr[i]);
    }

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = i+1; j < ans.size(); j++)
        {
            if(ans[i]==ans[j])
            {
                ans[j] = INT16_MIN;
            }

        }
        
    }
    vector<int>ans1;
    for(int i=0;i<ans.size();i++)
    {
         if(ans[i]!=INT16_MIN)
        {
            ans1.push_back(ans[i]);
        }
    }
    for(int i=0;i<ans1.size();i++)
    {
        cout<<ans1[i]<<" ";
    }
}