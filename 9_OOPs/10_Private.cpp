#include<iostream>
using namespace std ;

class Animal{
    public:
    int age;
    
};

class Dog:private Animal
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
    // cout<<d1.age;
    d1.print();
}