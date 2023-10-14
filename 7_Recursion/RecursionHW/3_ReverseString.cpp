#include<iostream>
using namespace std ;

void reverseString(string& str,int start,int end)
{
    if(end<=start)
    return;
    
    // Ek case solve karliya
    swap(str[end],str[start]);

    // Baaki recursion sambhal lega 
    reverseString(str,start+1,end-1);

}
int main()
{
   string str = "abcdefghij";
   int start =0;
   int end = str.length()-1;

   reverseString(str,start,end);

   cout<<"Reverse String is: "<<str;
}