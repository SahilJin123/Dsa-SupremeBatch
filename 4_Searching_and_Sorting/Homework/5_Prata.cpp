#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

bool isPossible(vector<int>cooksRanks,int nP,int mid)
{
    int currP=0;// Initially Cooked Prata Count
    for(int i=0;i<cooksRanks.size();i++)
    {
         int R = cooksRanks[i],j=1;
         int timeTaken =0;

         while (true)
         {
            if(timeTaken + j*R<=mid)
            {
                currP++;
                timeTaken+=j*R;
                j++;
            }else{
                break;
            }
         }

         if(currP>=nP)
         {
            return true;
         }    
    }
    return false;
}


int minTimeToCOmpleteOrder(vector<int>cooksRanks,int nP)
{
    int s =0;
    int highestRank = *max_element(cooksRanks.begin(),cooksRanks.end());
    int e = highestRank * (nP*(nP+1))/2;

    int ans = -1;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        if(isPossible(cooksRanks,nP,mid))
        {
            ans =mid;
            e = mid-1;
        }else{
            s=mid+1;
        }

    }
    return ans;

}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
       int nP,nC;
       cin>>nP>>nC;
       vector<int>cooksRanks;
       while(nC--)
       {
            int R;cin>>R;
            cooksRanks.push_back(R); 
       }

       cout<<minTimeToCOmpleteOrder(cooksRanks,nP)<<endl;
    }
    
}