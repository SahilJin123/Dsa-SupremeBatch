#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class parent{
    public:
    void chemistry()
    {
        cout<<"Parent Chemistry";
    }
};

class child:public parent
{
    public:
    void chemistry()
    {
        cout<<"child Chemistry";
    }
};

class Grandchild:public child
{
    public:
    void chemistry()
    {
        cout<<"Grandchild Chemistry";
    }
};
int main()
{

    Grandchild a;
    a.chemistry();
    a.child::chemistry();
}