#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class abc{
    public:

    int x,y;

    void print() const
    {
        // this pointer is passesd as hidden parameter 
        cout<<x<<" "<<y<<endl;
    }

    // Yeh function bilkul same hai upar vaale function se
    void printB() const
    {
        // this pointer is passesd as hidden parameter 
        cout<<this->x<<" "<<this->y<<endl;
    }
};
int main()
{
    abc obj1 = {1,2};
    abc obj2 = {3,4};
    obj1.print();
    obj2.print();
}
