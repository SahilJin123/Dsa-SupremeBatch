#include<iostream>
using namespace std;

void merge(int *arr,int s,int e)
{
    int mid = s + (e - s)/2;

    int len1= mid -s +1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    int k = s;
    for(int i=0;i<len1;i++)
    {
        left[i] = arr[k];
        k++;
    }

    k = mid+1;
    for(int i=0;i<len2;i++)
    {
        right[i] = arr[k];
        k++;
    }

    int leftIndex =0;
    int rightIndex =0;

    int mainArrIndex = s;

    while (leftIndex<len1 && rightIndex<len2)
    {
        if(left[leftIndex]<right[rightIndex])
        {
            arr[mainArrIndex++] = left[leftIndex++];
        }
        else{
            arr[mainArrIndex++] = right[rightIndex++];
        }
    }

    while(leftIndex<len1)
    {
        arr[mainArrIndex++] = left[leftIndex++];
    }

     while(rightIndex<len2)
    {
        arr[mainArrIndex++] = right[rightIndex++]; 
        
    }
    

}


void mergeSort(int *arr,int s,int e)
{
    if(s>=e)
    return;

    int mid = s + (e - s)/2;

    mergeSort(arr,s,mid);

    mergeSort(arr,mid+1,e);

    merge(arr,s,e);
}
int main()
{
   int arr[] = {4,5,1,2,9,0};

    int n = sizeof(arr)/sizeof(arr[0]);

    int start =0;
    int end = n-1;

    mergeSort(arr,start,end);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}