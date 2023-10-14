#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class abc{
    public:
    int x;
    int *y;
    const int z;

    abc()
    {
        x = 0;
        y = new int(0);
    }

    // abc(int _x,int _y,int _z=0)
    // {
    //     x = _x;
    //     y = new int(_y);
    //     z = _z; yeh line chalegi kyuki z const hai
    // }

    // Initialisation list and can also be used to redeclatre const variables
    abc(int _x,int _y,int _z=0) :x(_x),y(new int(_y)),z(_z);
    
    int getX() const
    {
        // x = 50;   ab getx koi member variable change nahi kar sakta hai

        // int f = 20;
        // y  =&f;
        return x;
    }


    void setX(int _val)
    {
        x = _val;
    }

    int getY() const
    {
        return *y;
    }

    void setY(int _val)
    {
        *y = _val;
    }

};

void printABC(const abc &a)
{
    cout<<a.getX()<<" "<<a.getY()<<endl;
}
int main()
{
    abc a(1,2);
    printABC(a);
}