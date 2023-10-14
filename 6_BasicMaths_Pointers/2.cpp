#include<iostream>
using namespace std ;
int main()
{
    int a =5;

    // pointer create

    int *ptr = &a;

    // access the value that ptr is pointing to

    cout<<"Address of a is: "<<&a<<endl;
    cout<<"Value stored in ptr is address of a is: "<<ptr<<endl;
    cout<<"value ptr is pointing to is: "<<*ptr<<endl;
    cout<<"Address of ptr is: "<<&ptr<<endl;
}