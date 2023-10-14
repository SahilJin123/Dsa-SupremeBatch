#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

  int findKthLargest(int nums[], int size, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i =0;i<k;i++)
        {
            pq.push(nums[i]);
        }

        int s =k;

        while(s!=size)
        {
            int newelement = nums[s];

            if(newelement>pq.top())
            {
                pq.pop();
                pq.push(newelement);
            }
            s++;
        }

        return pq.top();
    }

int kthSmallest(int arr[], int size, int k) {
        priority_queue<int> pq;
        for(int i=0;i<k;i++)
        {
            pq.push(arr[i]);
        }
        
        int s = k;
        while(s<size)
        {
            int newElement = arr[s];
            if(newElement<pq.top())
            {
                pq.pop();
                pq.push(newElement);
            }
            s++;
        }
        
        return pq.top();
        
        
        // priority_queue<int,vector<int>,greater<int>> pq;
        
        // for(int i=0;i<size;i++)
        // {
        //     pq.push(arr[i]);
        // }
        
        // int index = k-1;
        // while(index--)
        // {
        //     pq.pop();
        // }
        
        // return pq.top();
    }

int main()
{
    int arr[] = {10,5,20,4,15};
    int n =5;
    int k =2;
    int ans = kthSmallest(arr,n,k);
    cout<<"Ans is : "<<ans<<endl;

    ans = findKthLargest(arr,n,k);
    cout<<"Ans is : "<<ans;
}