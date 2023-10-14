#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
// Galat Hai code 
bool isPossible(int Rank[],int P,int L,int mid)
{
    int ChefCount = 1;
    // int minutesCount = 0;
    int PrataCount = 1;
    int ans = 0;
    // for(int i=0;i<=P;i++)
    while(P--)
    {
        if(ChefCount>L)
        return false;
        if(PrataCount*ChefCount + ans<=mid)
        {
            ans+=PrataCount*ChefCount;
            PrataCount++;
        }else{
            ChefCount++;
            PrataCount = 1;
            ans =0;
        }
    }

    if(ans<=mid)
    return true;

    return false;
}

int Prata(int Rank[],int P,int L)
{
    int s =0; 
    int e = Rank[L-1]*(P*(P+1)/2) ;
    int mid = s+(e-s)/2;
    int ans = -1;
    while(s<=e)
    {
        if(isPossible(Rank,P,L,mid))
        {
            ans =mid;
            e = mid-1;
        }else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main()
{
     int P;
     int L;
     cin>>P;
     cout<<endl;
     cin>>L;
     int Rank[L];
     for(int i=0;i<L;i++)
     {
        cin>>Rank[i];
     }

     cout<<Prata(Rank,P,L);
    
}