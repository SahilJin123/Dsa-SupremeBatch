#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class A{
    public:
    int physics;
    int chemistry;
    A()
    {
        chemistry  = 60;
    }
};


class B{
    public:
    int chemistry;

    B()
    {
        chemistry  = 70;
    }
};


class C:public A,public B{
    public:
    int maths;
     
};

int main()
{
    C obj;
    cout<<" "<<obj.A::chemistry<<" "<<obj.B::chemistry;
    
}