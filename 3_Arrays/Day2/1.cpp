#include<iostream>
#include<vector>
using namespace std ;
int main()
{
    vector<int> arr;

    cout<<arr.size()<<endl;
    cout<<arr.capacity()<<endl;
    arr.push_back(5);
    arr.push_back(6);

    for(int i =0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}