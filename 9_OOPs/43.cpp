#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class A{
    private:
    int x;

    public:
    
    A(int _val): x(_val) {}
    int getx() const {return x;}

    int setx(int _val) {x = _val;}

    friend class B;
    friend void print(A &);
};


class B
{
    public:
    void print(const A&a)
    {
        // cout<<a.getx();

        cout<<a.x<<endl;
    }
    B(/* args */);
    ~B();
};


void print(A &a)
{
    cout<<a.x;
}

B::B(/* args */)
{
}

B::~B()
{
}

int main()
{
    A a(5);
    B b;
    b.print(a);
    print(a);
}