#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class abc{
    public:

    int x,y;
    
    abc() : x(0),y(0) {}

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

int main()
{
    abc obj1 ;
    abc::print();
    abc obj2;
    abc::print(); 
    obj2.x = 10;
    obj2.y = 20;
    // obj2.print();

}