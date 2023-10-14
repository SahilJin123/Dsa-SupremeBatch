#include<iostream>
using namespace std ;
int main()
{
    int arr[] = {10,15,12,14};

    cout<<arr[0]<<endl;
    cout<<&arr[0]<<endl;
    cout<<&arr<<endl;
    cout<<&arr[0]<<endl;

    int *ptr = arr;
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*(ptr + 1) <<endl;
    
    cout<<*arr<<endl;
    cout<<*arr + 1<<endl;
    cout<<*(arr) +1<<endl;
    cout<<*(arr+1)<<endl;
    cout<<*(arr+2)<<endl;
    cout<<*(arr+2) + 5 <<endl;
}