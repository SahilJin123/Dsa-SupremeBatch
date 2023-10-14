#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class abc{
    public:

    static int x,y;

    void print() const
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
    abc obj1 ;
    obj1.x = 1;
    obj1.y = 2;
    obj1.print();
    abc obj2 ;
    obj2.x = 10;
    obj2.y = 20;
    obj1.print();
    obj2.print();
}
