#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class car{
    public:
    string name;
    int weight;
    int speed;

    void speedUp()
    {
        cout<<"Speeding Up "<<endl;
    }

    void breakUp()
    {
        cout<<"Break Marro"<<endl;
    }
};

class scorpio:public car{
 
};
int main()
{
    scorpio sahilwali;
    sahilwali.speedUp();
}