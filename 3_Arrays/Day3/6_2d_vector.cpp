#include<iostream>
#include<vector>
using namespace std ;
int main()
{
    // vector<vector<int> > arr;

    // vector<int> a{1,2,3};
    // vector<int> b{4,5,6,9,10};
    // vector<int> c{6,7,8};

    // arr.push_back(a);
    // arr.push_back(b);
    // arr.push_back(c);

    // for(int i =0;i<arr.size();i++)
    // {
    //     for(int j =0;j<arr[i].size();j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    int rows = 3;
    int cols = 5;
    vector<vector<int> > arr(rows,vector<int>(cols,0));
     for(int i =0;i<arr.size();i++)
    {
        for(int j =0;j<arr[i].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
   
   vector<vector<int>> arr1(5,vector<int>(5,-8));
   

}