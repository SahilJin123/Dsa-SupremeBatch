#include<iostream>
using namespace std ;

class Animal
{
    
    int age;
    int weight;
    
    public:
    void eat(){
        cout<<"Eating"<<endl;
    }

    void setAge(int age)
    {
        this->age=age;
    }
    int getAge()
    {
        return this->age;
    }

    void setweight(int weight)
    {
        this->weight=weight;
    }
    int getweight()
    {
        return this->weight;
    }

};

class Dog:public Animal{

};
 
int main()
{
    Dog d1;
    d1.eat(); 
    d1.setAge(10);
    cout<<d1.getAge();

}