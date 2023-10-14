#include<iostream>
using namespace std ;

int fact(int n)
{   
    
    // Base Case
    if(n==1)
    return 1;
    
    // Recursive Relation
    int chottiProblemAns = fact(n-1);
    int badiProblemAns = n*chottiProblemAns;
    return badiProblemAns;
}
int main()
{   
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    int ans=fact(n);

    cout<<"Answer is: "<<ans<<endl;
}