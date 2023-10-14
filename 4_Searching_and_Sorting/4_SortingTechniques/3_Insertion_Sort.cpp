#include<iostream>
#include<vector>   
using namespace std ;
int main()
{
    vector<int> arr{5,4,32,1,2};
    
    int n = arr.size();
    for(int round = 1;round<n;round++)
    {
        //  Step A-> fetch 
        int val=arr[round];
        // Step B ->Compare
        int j = round-1;
        for (; j>=0; j--)
        {
            if(arr[j]>val)
            {
                // Step c :shift
                arr[j+1]=arr[j];
            }
            else{
                // rukna hai
                break;
            }
        }

        // Step D ->Copy karlo
        arr[j+1]=val;
    }
    

    for(int i=0;i<arr.size();i++)
     {
        cout<<arr[i]<<" ";
     }
}