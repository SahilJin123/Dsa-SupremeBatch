#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;
int lastOccurence(vector<int> v,int target)
{
   int s = 0;
   int e = v.size() - 1;
   int mid = s + (e-s)/2 ;
    int ans = -1 ;
   while (e>=s)
   {
    if(v[mid]==target)
    {
        ans =mid;
        s = mid +1;
        
    }
    else if(target>v[mid])
    {
        s = mid +1;
    }
    else if(target<v[mid])
    {
        e = mid -1;
    } 
    mid = s + (e-s)/2 ;
   }
    return ans;
}

int main()
{
   vector <int> v{1,3,3,3,3,3,4,4,6,7};
   int target = 4;
   int indexofFirstOcc = lastOccurence(v,target);

   cout<<"Ans is "<<indexofFirstOcc<<endl;
}