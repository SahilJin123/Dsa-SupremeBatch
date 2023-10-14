#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class abc{
    int x;
    int *y;
    public:

    abc()
    {
        x=0;
        y = new int(0);
    }


    abc(int _x,int _y)
    {
        x=_x;
        y = new int(_y);
    }


    void setX(int val) 
    {
        x = val;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return *y ;
    }


    void setY(int val)
    {
        *y = val;
    }

};


// int const pqr(int a,int b)
// {
//     int c = a;
//     int e = b;
//     c = 10;
//     cout<<c<<" "<<e<<endl;
// }

void Printabc(const abc &a)
{
    cout<<a.getX()<<" "<<a.getY()<<endl;
}
int main()
{
    // abc a;
    // cout<<a.getX()<<endl;
    // cout<<a.getY()<<endl;
    abc b(2,5);
    Printabc(b);

}