// Doubt

#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{   
    int width = 4;
    int rows = 5;
    int cols =3;
    int*** arr = new int**[width];  

    for(int i=0;i<rows;i++)
    {
        **(arr[i]) = new int*[rows];
    }

    for(int i=0;i<rows;i++)
    {
        *(arr[i]) = new int[cols];
    }

    for (int i = 0; i < width; i++)
    {
        for(int j=0;j<rows;j++)
        {
            for(int r=0;r<cols;r++)
            {
                cout<<arr[i][j][r]<<" ";
            }
            cout<<endl;
        }
        cout<<endl; 
    } 
  
}