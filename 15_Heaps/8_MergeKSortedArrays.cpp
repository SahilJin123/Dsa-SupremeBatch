#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std ;

class info{
    public:
    int data;
    int row;
    int col;

    info(int data,int row,int col)
    {
        this->data=data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    bool operator()(info* a,info* b)
    {
        return a->data > b->data;
    }
};
vector<int> MergeKSortedArrays(int arr[][4],int k,int n)
{
    priority_queue<info*,vector<info*>,compare> pq;


    // hr array ka first element insert karo
    for (int i = 0; i < k; i++)
    {
        info* temp = new info(arr[i][0],i,0);
        pq.push(temp);
    }

    vector<int> ans;

    while(!pq.empty())
    {
        info* temp = pq.top();
        int topElement = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;
        pq.pop();
        ans.push_back(topElement);

        if(topCol+1<n)
        {
            info* newinfo =  new info(arr[topRow][topCol+1],topRow,topCol+1);
            pq.push(newinfo);
        }
    }

    return ans;
    
}
int main()
{
    int arr[][4] = {{2,4,6,8},{1,3,5,7},{8,9,10,11}};
    int k = 3;
    int n = 4;

    vector<int> ans = MergeKSortedArrays(arr,k,n);

    for(auto it: ans)
    {
        cout<<it<<" ";
    }
}