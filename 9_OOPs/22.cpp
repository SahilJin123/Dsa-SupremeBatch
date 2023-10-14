#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class Animal{
    public:

    void speak()
    {
        cout<<"Speaking"<<endl;
    }
};

class dog:public Animal{
    public:

    void speak()
    {
        cout<<"Barking"<<endl;
    }
};
int main()
{
    // Animal* a = new Animal();
    // a->speak();

    // dog* a = new dog;
    // a->speak();


    // Upcasting
    Animal* a = new dog;
    a->speak();

    // Downcasting 
    dog* b = (dog* )new Animal();
    b->speak();
}