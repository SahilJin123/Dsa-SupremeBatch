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
    dog d1;
    d1.speak();
    d1.Animal::speak();
}