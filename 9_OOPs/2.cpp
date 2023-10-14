#include<iostream>
using namespace std ;

class Animal{

    public:
    int age;
    string name;
    

    // Behaviour

    void eat()
    {
        cout<<"Eating";
    }

    void sleep()
    { 
        cout<<"Sleeping";
    }

};

int main()
{
    // Object Creation
    //1. Static
    Animal ramesh;
    ramesh.age =12;
    ramesh.name = "LION";
    cout<<"Age of Ramesh is: "<<ramesh.age <<endl;
    cout<<"Name of Ramesh is: "<<ramesh.name <<endl;
    ramesh.eat();
    ramesh.sleep();
    // 2.  Dynameic Memory
}   