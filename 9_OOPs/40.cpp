#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class abc{
    public:

    static int x,y;

    static void print()
    {
        // this pointer is passesd as hidden parameter 
        cout<<x<<" "<<y<<endl;
    }

    // Yeh function bilkul same hai upar vaale function se
    // void printB() const
    // {
    //     // this pointer is passesd as hidden parameter 
    //     cout<<this->x<<" "<<this->y<<endl;
    // }
};

int abc::x;
int abc::y;
int main()
{
    abc::x = 1;
    abc::y = 2;
    abc::print();
    abc obj2 ;
    obj2.x = 10;
    obj2.y = 20;
    obj2.print();

}