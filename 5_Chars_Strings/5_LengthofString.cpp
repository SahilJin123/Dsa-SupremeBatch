#include<iostream>
#include<string.h>
using namespace std ;

int getlength(char name[])
{
    int length=0;
    int i =0;

    while(name[i]!='\0')
    {
        length++;
        i++;
    }
    return length;
}
int main()
{  
   char name[100];
   
   cout<<"Enter the Name: "; 
   cin>>name;     

   cout<<"Length is :"<<getlength(name);
    
    // Inbuilt Function
    cout<<"Length is :"<<strlen(name);

}