#include<iostream>
using namespace std ;


void merge(int* arr,int start,int end)
{
      int mid = (end + start)/2;

      int len1 = mid -start + 1;
      int len2 = end - mid;

      int * left = new int[len1];

      int * right = new int[len2];

    //   Copy Values
    int k=start;
    for(int i=0;i<len1;i++)
    {
        left[i] = arr[k];
        k++;
    }

     k=mid+1;
    for(int i=0;i<len2;i++)
    {
        right[i] = arr[k];
        k++;
    }


    // Merge Logic

    int leftindex = 0;
    int rightindex = 0;

    int mainArrayIndex = start;

    while(leftindex<len1 && rightindex<len2)
    {
        if(left[leftindex]<right[rightindex])
        {
            arr[mainArrayIndex++] = left[leftindex++];
        }
        else{
            arr[mainArrayIndex++] = right[rightindex++];

        }
    }

    // Copy Logic for left array

    while (leftindex<len1)
    {
        arr[mainArrayIndex++] = left[leftindex++];
    }
    
    // Copy Logic for Right array
    while (rightindex<len2)
    {
        arr[mainArrayIndex++] = right[rightindex++];
    }
    
    // TOdo :left and right wala created array
}
void mergeSort(int* arr,int start,int end){
    //  Base Case
     if(start==end)
     return;

     int mid = (end + start)/2;
    //   Left
     mergeSort(arr,start,mid);

    // Right Sort
      mergeSort(arr,mid+1,end);

    //   Now merge 2 Sorted arrays

      merge(arr,start,end);
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