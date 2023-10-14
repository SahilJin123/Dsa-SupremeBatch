#include<iostream>
#include<string.h>
using namespace std ;
void convertintouppercase(char arr[])
{
    for(int i=0;i<strlen(arr);i++)
    {   
        if(arr[i]!=' '  && arr[i]>='a' && arr[i]<='z')             //if ke bina chalake dekhna tabh full name uppercase main convert nahi hoga kyuki [space(20) - 97 + 65] negative ho jayega
        arr[i] = arr[i] - 'a' + 'A';
    }
}
int main()
{
   char arr[100];
   cout<<"Enter the arr: "; 
   cin.getline(arr,100);  
   convertintouppercase(arr);
   cout<<arr; 
}