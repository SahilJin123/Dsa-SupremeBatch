#include<iostream>
using namespace std ;

int exponent(int n)
{   

    if(n==0)
    return 1;
    
    return 2*exponent(n-1);
}
int main()
{
    int ans=exponent(5);
    cout<<ans;
}