#include<iostream>
#include<string.h>
using namespace std ;

void reversestring(char name[])
{
    int i =0;
    int j = strlen(name)-1;
    
    while (j>=i)
    {
        swap(name[i],name[j]);
        i++;
        j--;
    }
    
}
int main()
{  
   char name[100];
   
   cout<<"Enter the Name: "; 
   cin>>name;     
   reversestring(name);
   cout<<name;

}