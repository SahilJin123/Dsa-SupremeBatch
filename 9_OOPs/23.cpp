#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class Animal{
    public:

    Animal()
    {
        cout<<"I am inside Animal COnstructor"<<endl;
    }
     void speak()
    {
        cout<<"Speaking"<<endl;
    }
};

class dog:public Animal{
    public:
    dog()
    {
        cout<<"I am inside dog COnstructor"<<endl;
    }
    void speak()
    {
        cout<<"Barking"<<endl;
    }
};
int main()
{
    // Animal* a = new Animal;

    // cout<<endl;

    // dog* b = new dog;
    // cout<<endl;
    // Animal* c = new dog; 
    // cout<<endl;

    dog* d = (dog*)new Animal;
}