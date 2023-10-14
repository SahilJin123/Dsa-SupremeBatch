#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std ;


// **********************************************************Brute Force Approach use of Arrays ********************************************************************


int largestRectangleArea(vector<int>& heights) {
    
    int maxArea=0;
    for(int i =0;i<heights.size();i++)
    {   
        int leftwidth =0;
        int rightwidth =0;
        int curr = heights[i];
        for(int j =0;j<i+1;j++)
        {
            if(heights[j]>=curr)
            {
                leftwidth++;
            }else{
                leftwidth =0;
            }
        }
        for(int j = i+1;j<heights.size();j++)
        {
            if(heights[j]>=curr)
            {
                rightwidth++;
            }else{
                break;
            }
        }
        int area = curr*(leftwidth+rightwidth);
        maxArea = max(area,maxArea);
    }
    return maxArea;
}

int main()
{
    vector<int>heights{2,1,5,6,2,3};
    int ans = largestRectangleArea(heights);
    cout<<ans;
}