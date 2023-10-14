#include<iostream>
using namespace std ;

class Animal{
    public:
    int age;
    
};

class Dog:protected Animal
{
    public:
    void print()
    {
        cout<<age;
    }
};
int main()
{
    Dog d1;
    d1.print();
}