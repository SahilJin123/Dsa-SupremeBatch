#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class Maths{
    public:

    int sum(int a,int b)
    {
        return a+b;
    }

    int sum(int a,int b,int c)
    {
        return a+b+c;
    }
    int sum(int a,float b)
    {
        return a+b+100;
    }
};
int main()
{
    Maths obj;
    cout<<obj.sum(2,5.12f)<<endl;
    
    cout<<obj.sum(2,5)<<endl;
    
    cout<<obj.sum(2,5,7)<<endl;
}