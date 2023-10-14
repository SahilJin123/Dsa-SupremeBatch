#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class car{
    public:
    int age ;
    int weight;
    string name;

    void speedUp(){
        cout<<"Speeding Up "<<endl; 
    }
};

class Scorpio:public car{

};

class fortuner:public car{

};

int main()
{
    Scorpio s11;
    s11.speedUp();

    fortuner f11;
    f11.speedUp();
}