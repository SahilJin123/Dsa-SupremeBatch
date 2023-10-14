#include<iostream>
using namespace std ;
int main()
{  
    // Yeh program hume batata hai end main null character present hai
   char name[100];

   cin>>name;     //"Sahil"

   for (int i = 0; i < 10; i++)
   {
    cout<<"Index: "<<i<<" Value: "<<name[i]<<endl;
   }


   int value = (int)name[5];
   cout<<value;                     //Null character ki ascii value 0 hotti hai
   
} 