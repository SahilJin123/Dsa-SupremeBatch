#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{

//    *******************Constant data ,But non constant Pointer *****************



//    const int* a = new int(2); // const data,Non const Pointer
   int const* a = new int(2); //Same as line number 6
   cout<<*a<<endl;
//    *a=20;       can't change the content of pointer
//    cout<<*a<<endl; 
   int b = 20;
   a = &b; // Pointer itself can be reassigned
   cout<<*a<<endl;







//    *******************Constant Pointer ,But non constant data *****************

// int *const a = new int(2);
// cout<<*a<<endl;
// *a = 20;  //chal jayega
// cout<<*a<<endl;

// int b = 50;
// a = &b; // Nahi chalega



//    *******************Constant Pointer ,Constant data *****************


// const int *const a = new int(2);
// cout<<*a<<endl;
// // *a = 20;  //Nahi chalega 
// // cout<<*a<<endl;

// // int b = 50;
// // a = &b; // Nahi chalega
 

}