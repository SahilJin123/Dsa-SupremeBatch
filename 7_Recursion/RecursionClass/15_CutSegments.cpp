#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

int solve(int n,int x,int y,int z,vector<int>output)
{
    if(n==0)
    {
        for(auto it:output)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return 0;
    }
    
    if(n<0)
    {
        return INT_MIN;
    }

    output.push_back(x);
    int ans1 = solve(n-x,x,y,z,output) + 1;
    output.pop_back();
    output.push_back(y);
    int ans2 = solve(n-y,x,y,z,output) + 1;
    output.pop_back();
    output.push_back(z);
    int ans3 = solve(n-z,x,y,z,output) + 1;
    

    int ans = max(ans1,max(ans2,ans3));
    return ans;
}
int main()
{
    int n =7;
    int x =5;
    int y=2;
    int z=2;
    
    // Solve return maximum number of segments
    vector<int>output;
    int ans = solve(n,x ,y,z,output);
    
    if(ans <0)
    ans =0;
    cout<<"Answer is: "<<ans<<endl;
}