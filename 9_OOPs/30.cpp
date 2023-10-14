#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class abc{
    public:
    mutable int x;
    int *y;

    abc()
    {
        x = 0;
        y = new int(0);
    }

    abc(int _x,int _y)
    {
        x = _x;
        y = new int(_y);
    }
//  ab suppose function const hai par mai value phir bhi change karna chahta huto kaise karunga ??
// mai us variable ko muttable bana dunga
    int getX() const
    {
         *y = 50;  //ab yaha pe koi error nahi aayega
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