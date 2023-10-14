// Left to Right Searching

#include<iostream>
using namespace std ;

void lastOccChar(string str,char key,int index,int& ans)
{
    if(index==str.length())
    return;
    
    if(str[index]==key)
    ans = index;

    lastOccChar(str,key,index+1,ans);
}
int main()
{ 
   string str = "abbdfbc";

   int index =0;
   char key = 'c';
   int ans;
   lastOccChar(str,key,index,ans);

   cout<<"Answer is: "<<ans;
}