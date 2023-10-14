#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

// Shallow and deep copy



class abc{
    public:
    int x;
    int* y;

    abc(int _x,int _y) : x(_x), y(new int(_y)){}     
    
    // default dumb copy constructor : it does shallow copy 
    // abc(const abc &obj)
    // {
    //     x = obj.x;
    //     y = obj.y;
    // }

    // Our Smart deep copy
    abc(const abc &obj)
    {
        x = obj.x;
        y = new int(*obj.y);
    }

    void print() const{
        printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n",x,y,*y);
    }

};
int main()
{
    cout<<"Printing a"<<endl;
    abc a(1,2);
    a.print();

    cout<<"Printing b"<<endl;
    abc b(a);   //call Hota hai copy constructor
    // par humne copy constructor call nahi kiya toh ek dumb copy constructor call hota hai
    b.print();

    cout<<"Printing b"<<endl;
    *b.y = 20;
    b.print();
    
    cout<<"Printing a"<<endl;
    a.print();
}


// ek ek bar constructor ko chalake dekho 