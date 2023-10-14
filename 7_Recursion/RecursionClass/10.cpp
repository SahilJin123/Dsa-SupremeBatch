#include<iostream>
using namespace std ;

void printdigits(int number)
{
    if(number==0)
    
    return;

    int digit = number%10;
    // cout<<digit<<endl;
    int numbervalue = number/10;

    printdigits(numbervalue);
    
    cout<<digit<<" ";

}
int main()
{
  int n=627;
  // cout<<"Enter the number: "<<endl;
  // cin>>n;
  printdigits(n);
}