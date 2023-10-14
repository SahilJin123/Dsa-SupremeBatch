#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int rows = 5;
    int cols =3;
    int** arr = new int*[5];  

    for(int i=0;i<rows;i++)
    {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl; 
    } 

    // Deallocate memory in 2D arrays

     for (int i = 0; i < rows; i++)
     {
        delete []arr[i];
     }

     delete []arr;
     
  
}