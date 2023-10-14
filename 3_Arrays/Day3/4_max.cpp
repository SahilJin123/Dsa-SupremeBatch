#include<iostream>
using namespace std ;

int getmax(int arr[][3],int rows,int cols)
{  
    int maxi = INT16_MIN;
   for(int i =0;i<rows;i++)
    {   
        for(int j =0;j<cols;j++)
        {
            if(arr[i][j]>maxi)
            {
                maxi = arr[i][j];
            }
        }
    }
    return maxi;
}

int main()
{
  int arr[3][3] = {{1,2,3},{4,5,6},{2,5,7}};

  int ans = getmax(arr,3,3);

  cout<<"Ans is: "<<ans;

}