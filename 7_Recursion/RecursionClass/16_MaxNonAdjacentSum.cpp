#include<iostream>
#include<vector>
#include<limits.h>
using namespace std ;

void solve(vector<int> arr,int index,int sum,int &maxi)
{
    if(index>=arr.size())
    {
        maxi =max(sum,maxi); 
        return;
    }
    
    
    solve(arr,index+1,sum,maxi);

    solve(arr,index+2,sum + arr[index],maxi);
}
int main()
{
    vector<int> arr{1,2,3,1,3,5,8,1,9};

    int sum =0;
    int index =0;
    int maxi = INT_MIN;
     solve(arr,index,sum,maxi);

    cout<<"Answer is :"<<maxi;
}