#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class A{
    public:
    int physics;
};


class B{
    public:
    int chemistry;
};


class C:public A,public B{
    public:
    int maths;
    void print()
    {
        cout<<physics<<endl;
        cout<<chemistry<<endl;
        cout<<maths<<endl;
    }
    int totalpercentage = (maths + physics + chemistry)/3; 
};

int main()
{
    C sahil;
    sahil.physics = 100;
    sahil.chemistry= 78;
    sahil.maths = 100;

    cout<<sahil.maths<<endl;
    cout<<sahil.chemistry<<endl;
    sahil.print();
    cout<<"Total Percentage "<<sahil.totalpercentage;
}