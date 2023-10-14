#include<iostream>
using namespace std ;

void reversecounting(int n)
{   
    // Base Case
    if(n==0)
    return;
    
    // Processing
    cout<<n<<endl;
    
    // Recursive Relation
    reversecounting(n-1);


        
    // Processing

    // cout<<n<<endl;  Straight Counting
}
int main()
{   
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    reversecounting(n);
}