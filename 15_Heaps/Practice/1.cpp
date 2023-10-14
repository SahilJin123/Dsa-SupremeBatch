#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class Heap{
    public:
    int arr[100];
    int size;

    Heap()
    {
        size = 0;
    }
    void insert(int value)
    {
        // Value insert karo end main
        size = size + 1;
        int index =  size;
        arr[index] = value;

        // iss value ko place karna hai uski right position pe

        while(index > 1)
        {
            int parentIndex = index/2 ;

            if(arr[index] >arr[parentIndex])
            {
                swap(arr[index],arr[parentIndex]);
                index = parentIndex;
            }else{
                break;
            }

        } 
    }

    void deleteValue()
    {
        // replace root node with last node value
        arr[1] =arr[size];
        size--;

        // place root node ka data on its correct position

        int index = 1;

        while(index < size)
        {
            int left = 2*index;
            int right = 2*index + 1;

            int largest = index ;
            if(left < size && arr[largest] < arr[left])
            {
                largest = left;
            }

            if(right < size && arr[largest] < arr[right])
            {
                largest = right;
            }

            if(largest==index)
            {
                return;
            }else{
                swap(arr[largest],arr[index]);
                index = largest;
            }
        }
    }
};


void heapify(int arr[],int n,int i)
{
    int index = i;
    int leftindex = 2*index;
    int rightindex = 2*index + 1;

    int largest = index;

    if(leftindex <= n && arr[largest] < arr[leftindex])
    {
        largest = leftindex;
    }

    if(rightindex <= n && arr[largest] < arr[rightindex])
    {
        largest = rightindex;
    }

    if(largest!=index)
    {
        swap(arr[largest],arr[index]);
        index = largest;
     
        heapify(arr,n,index);
    }
    
}

void buildHeap(int arr[],int n)
{
    for(int i = n/2; i>0;i--)
    {
        heapify(arr,n,i);
    }
}


void Heapsort(int arr[],int size)
{

    while(size!=1)
    {
        swap(arr[1],arr[size--]);
        heapify(arr,size,1);
    }
}

int main()
{
    // Heap h;
    // h.insert(50);
    // h.insert(30);
    // h.insert(70);
    // h.insert(40);
    // h.insert(80);
    // h.insert(100);
    
    // for(int i=1;i<=h.size;i++)
    // {
    //     cout<<h.arr[i]<<" ";
    // }
    // cout<<endl;

    // h.deleteValue();

    // for(int i=1;i<=h.size;i++)
    // {
    //     cout<<h.arr[i]<<" ";
    // }
    // cout<<endl;

    int size = 6;
    int arr[] = {-1,34,23,56,71,21,45};

    buildHeap(arr,size);
    Heapsort(arr,size);

    for(int i=1;i<=size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}