#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

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
    // abc(const abc &obj)
    // {
    //     x = obj.x;
    //     y = new int(*obj.y);
    // }

    void print() const{
        printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n",x,y,*y);
    }

    // One More Problem with shallow copy

    ~abc()
    {
        delete y;
    }

};
int main()
{
    abc *a = new abc(1,2);
    abc b = *a ;
    delete a;
    b.print();  //garbage value print hogai y ki
    return 0;
}