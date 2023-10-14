#include<iostream>
#include<vector>
using namespace std ;

int dividebyBinarySearch(int dividend ,int divisor )
{
    int s =0;
    int e = abs(dividend);
    int mid = s + (e-s)/2;
    int ans =1;
    while (e>=s)
    {
       if(abs(mid*divisor)==abs(dividend))
        {  
            ans =mid;
            break; 
        }
       
       
        if(abs(mid*divisor)<=abs(dividend))
        {
            ans = mid;
            s = mid+1;
        }
        else if(abs(mid*divisor)>abs(dividend))
        {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }

    if((divisor<0 && dividend>0) || (divisor>0 && dividend<0))
    {
        ans = ans*-1;
    }
    
    return ans;
}
int main()
{
  int divisor = 7;  
  int dividend = -21;
  int ans = dividebyBinarySearch(dividend,divisor);
  cout<<ans;
}