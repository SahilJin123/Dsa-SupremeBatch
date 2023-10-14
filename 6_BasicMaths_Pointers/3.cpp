#include<iostream>
using namespace std ;
int main()
{    
    // Null Poin ter
    int a =5;
    int *ptr =&a;

    int *dusraptr = ptr;

     cout<<ptr<<endl;
     cout<<dusraptr<<endl;

      cout<<*ptr<<endl;
     cout<<*dusraptr<<endl;
}