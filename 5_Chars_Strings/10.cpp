#include<iostream>
#include<string>
using namespace std ;
int main()
{   
   
   char arr[100];

   cout<<"Enter the name with null character and than print the ans "<<endl;

    cin>>arr;
    arr[1]='\0';
    arr[4]='\0';

   cout<<"Output is: "<<endl;
    for(int i =0;i<7;i++)
   {
    cout<<arr[i]<<" ";
   }







    // string str;
    // cout<<"Enter the name with null character and than print the ans "<<endl;
    
    // cin>>str;
    // str[1]='\0';
    // str[4]='\0';
    // cout<<str;
}