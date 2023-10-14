// Constructor Creation

#include<iostream>
using namespace std ;

class Animal{

    int weight;
    public:
    int age;
    string name;
    
    
    // default Constructor
    Animal()
    {
        this->age = 0;
        this->weight = 0;
        this->name = " ";
        cout<<"Default constructor called"<<endl;
    }

    // Parameterised constructor
    // Animal(int age)
    // {
    //     this->age = age;
    //     cout<<"Parameterised constructor called"<<endl;
    // }
    // Animal(int age,int weight)
    // {
    //     this->age = age;
    //     this->weight = weight;
    //     cout<<"Parameterised constructor 2 called"<<endl;
    // }

    // Animal(int age,int weight,string name)
    // {
    //     this->age = age;
    //     this->weight = weight;
    //     this->name = name;
    //     cout<<"Parameterised constructor 3 called"<<endl;
    // }

    // Copy Constructor

    // Animal(Animal &obj)
    // {
    //     this->weight = obj.weight;
    //     this->age = obj.age;
    //     this->name = obj.name;
    //     cout<<"Copy Constructor "<<endl;
    // }

    
    // Behaviour

    void eat()
    {
        cout<<"Eating";
    }

    void sleep()
    {
        cout<<"Sleeping";
    }

    int getweight()
    {
        return weight;   
    }

    void setweight(int weight)
    {  
        this->weight = weight;
    }

    void print()
    {
         cout<<this->age<<" ";
         cout<<this->weight<<" ";
         cout<<this->name<<endl;
    }
};

int main()
{
   Animal a;
   a.age = 10;
   a.setweight(20);
   a.name = "Babbar";

    Animal b = a;
    // cout<<b.getweight();
    cout<<"a -> :";
    a.print();
    cout<<"b -> :";
    b.print();

    a.name[0]='G';

    a.print();
    b.print();

}