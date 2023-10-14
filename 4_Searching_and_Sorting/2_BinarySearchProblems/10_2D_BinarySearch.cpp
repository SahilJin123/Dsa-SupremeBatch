#include<iostream>
#include<vector>
using namespace std ;

bool BinarySearch_2D(int arr[][4],int rows,int cols,int target)
{
     int s =0;
     int e = rows*cols -1;
     int mid = s + (e - s)/2;
    

     while(e>=s)
     {
        int rowIndex = mid/cols;
        int colIndex = mid%cols;

        if(arr[rowIndex][colIndex]==target)
        {
            // ans.push_back(rowIndex);
            // ans.push_back(colIndex);
            cout<<"RowIndex: "<<rowIndex<<" ColIndex: "<<colIndex<<endl;
            return true;
        } 
        
         if(arr[rowIndex][colIndex]<target)
        {
            s =mid+1;
        }else{
            e = mid-1;
        }
        
        mid = s + (e - s)/2;

     }
   return false;
}
int main()
{
    int arr[5][4] = { {1,22,23,34},{35,36,47,48},{49,50,61,72},{73,74,85,86},{97,108,109,200} };
    int target = 49;
    int rows =5;
    int cols = 4;
    bool ans = BinarySearch_2D(arr,rows,cols,target);

    if(ans)
    cout<<"Found";
    else
    cout<<"Not Found";
}