#include<iostream>
using namespace std ;

void transpose(int arr[][3],int rows,int cols,int transposeArr[][3])
{  
   for(int i =0;i<rows;i++)
    {   
        for(int j =0;j<cols;j++)
        {
            // swap(arr[i][j],arr[j][i]);
            transposeArr[j][i]=arr[i][j];
        }
    }
}

void printarray(int arr[][3],int rows,int cols)
{
    for(int i =0;i<rows;i++)
    {   
        for(int j =0;j<cols;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
  int arr[3][3] = {{1,2,3},{4,5,6},{2,5,7}};
   
   int transposeArr[3][3];
   printarray(arr,3,3);
   transpose(arr,3,3,transposeArr);
   cout<<"After Transpose"<<endl;
   printarray(transposeArr,3,3);
}