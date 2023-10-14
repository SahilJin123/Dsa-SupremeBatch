#include<iostream>
using namespace std ;

bool findkey(int arr[][3],int rows,int cols,int key)
{
   for(int i =0;i<rows;i++)
    {   
        for(int j =0;j<cols;j++)
        {
            if(arr[i][j]==key)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
  int arr[3][3] = {{1,2,3},{4,5,6},{2,5,7}};

  bool ans = findkey(arr,3,3,5);

  if(ans)
  {
    cout<<"Found";
  }else{
    cout<<"Not Found";
  }

}