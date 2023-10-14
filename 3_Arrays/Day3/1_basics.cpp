#include<iostream>
using namespace std ;
int main()
{
    // Declare 2D array
    int arr[3][4];

    // initialisation
    int brr[3][3] = {{1,2,3},{4,5,6},{2,5,7}};
    
    // Row wise Print
    for(int i =0;i<3;i++)
    {
        for(int j =0;j<3;j++)
        {
            cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }

    // Column wise Print
    for(int i =0;i<3;i++)
    {
        for(int j =0;j<3;j++)
        {
            cout<<brr[j][i]<<" ";
        }
        cout<<endl;
    }
}