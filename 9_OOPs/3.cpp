#include<iostream>
using namespace std ;

class Animal{

    private:
    int weight;
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

    int getweight()
    {
        return weight;   
    }

    void setweight(int weight)
    {  
        this->weight = weight;
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
    cout<<endl;
    ramesh.sleep();
    cout<<endl;
    ramesh.setweight(101);
    cout<<ramesh.getweight();
    cout<<endl;
    // 2.  Dynameic Memory

    Animal* suresh = new Animal;
    
    (*suresh).age = 15;
    (*suresh).name = "billi";

    suresh->age = 17;
    suresh->name = "Kutta";

    cout<<"Age of suresh is: "<<(*suresh).age <<endl;
    cout<<"Name of suresh is: "<<(*suresh).name <<endl;
    (*suresh).eat();
    cout<<endl;
    (*suresh).sleep();
    (*suresh).setweight(101);
    cout<<endl;
  
}   