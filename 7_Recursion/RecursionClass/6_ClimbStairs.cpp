#include<iostream>
using namespace std ;


 int climbStairs(int n) {

        if(n==1)
        // count+=1;
        return 1;


        if(n==2)
        // count+=2; 
        return 2;

        int count = climbStairs(n-1) + climbStairs(n-2);

        return count;
}
int main()
{
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;

    int ans = climbStairs(n);
    cout<<"Answer is: "<<ans;

}