#include<iostream>
using namespace std ;
int sqrt(int x)
{
    int s =0;
    int e = x;
    int mid = s + (e-s)/2 ;
    int ans = -1;
    while(e>=s)
    {
        if(mid*mid==x)
        {
            return mid;
        }
        if(mid*mid>x)
        {
            e = mid-1;
        }
        else if(mid*mid<x)
        {   
            ans = mid ;
            s = mid + 1;
        }
        mid = s + (e-s)/2 ;
    }
    return ans;
}
int main()
{
    int x;
    cout<<"Enter the Number :"<<endl;
    cin>>x;
    int ans = sqrt(x);
    double steps = 0.1;
    double finalans = ans;
    int percision;
    cout<<"Enter the floating Point percision for thhe Number :"<<endl;
    cin>>percision;

    for(int i =1;i<=percision;i++)
    {
        for(double j = finalans;j*j<=x;j=j+steps)
        {
            finalans = j;
        }
        steps = steps /10 ;
    }


    cout<<"Final Answer is :"<<finalans;

}