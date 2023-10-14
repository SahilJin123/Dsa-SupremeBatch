#include<iostream>
#include<string.h>
using namespace std ;

void replacespaces(char name[])
{
    for(int i=0;i<strlen(name);i++)
    {
        if(name[i]==' ')
        {
            name[i]='@';
        }
    }
    
}
int main()
{  
   char name[100];
   cout<<"Enter the Name: "; 
   cin.getline(name,100);   
   replacespaces(name);
//    cout<<strlen(name)<<endl;
   cout<<name;
   
}