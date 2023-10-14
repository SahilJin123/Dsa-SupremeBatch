#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class print{

    public:
    int age;
    int weight;
    int number;

    // void operator<<()
    // {
    //     cout<<age<<endl;
    //     cout<<weight<<endl;
    //     cout<<number<<endl;
    // }

    friend istream& operator >>(istream& input,print &obj);
    friend ostream& operator <<(ostream& output,print &obj);
    
};

istream& operator >>(istream& input,print &obj)
{
    input>>obj.age;
    input>>obj.weight;
    input>>obj.number;
    return input;
}
ostream& operator <<(ostream& output,print &obj)
{
    output<<obj.age;
    cout<<endl;
    output<<obj.weight;
    cout<<endl;
    output<<obj.number;
    cout<<endl;
    return output;
}
int main()
{
    print obj,obj1;
    obj.age = 21;
    obj.weight = 60;
    obj.number = 6284;

    cin>>obj>>obj1;
    cout<<obj;    
}