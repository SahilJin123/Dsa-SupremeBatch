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

    ~Animal()
    {
        cout<<"Destructor Called"<<endl;
    }
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

    cout<<"a object is Created "<<endl;
   Animal a;
   a.age = 10;
   a.setweight(20);
   a.name = "Sahil";

   cout<<"b object is Created "<<endl;
   Animal* b = new Animal();
    b->age = 12;

    // Manually

    delete b;

}