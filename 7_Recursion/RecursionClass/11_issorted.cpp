#include<iostream>
using namespace std ;

bool issorted(int arr[],int size,int index)
{
    if(index>=size)
    return true;

    if(arr[index]>arr[index+1])
    return false; 

    return issorted(arr,size,index+1);
}

int main()
{
    int arr[] = {5,6,7,1};
    bool ans = issorted(arr,1,0);

    if(ans)
    cout<<"Is Sorted"<<endl;
    else
    cout<<"Not Sorted"<<endl;
 
}
