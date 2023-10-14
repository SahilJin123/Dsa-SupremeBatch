#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class Heap{
    public:
    int *arr;
    int size;
    int index;
    
    Heap(int size){
        this->size=size;
        arr = new int[size];
        index=0;
    }
    void insert(int value)
    {
        // value insert karo
        
        index=index+1;                  
        arr[index]=value;
        int childIndex = index;

        // iss value ko place karna hai iski correct position
        while(childIndex>1)
        {
            int parentIndex = childIndex/2;
            if(arr[childIndex]>arr[parentIndex])
            {
                swap(arr[childIndex],arr[parentIndex]);
                childIndex=parentIndex;
            }else{
                break;
            }
        }
    }

    void deleteData()
    {
        // replace root node value with the last node
        arr[1] = arr[index];
        index = index-1;

        int i = 1;
        while(i<index)
       {
            int left = 2*i;
            int right = 2*i + 1;

            int largest = i;
            if(left<index && arr[largest]<arr[left])
            {
                largest = left;
            }

            if(right<index && arr[largest]<arr[right])
            {
                largest = right;
            }

            if(largest==i)
            {
                return;
            }else{
                swap(arr[i],arr[largest]);
                i = largest;
            }
        }
        
    }

};
int main()
{
    Heap h(10);
    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);


    cout<<"Printing The Heap :"<<endl;
    for(int i=1;i<=h.index;i++)
    {
        cout<<h.arr[i]<<" ";
    }
    cout<<endl;
    
    h.deleteData();
    cout<<"Printing The Heap :"<<endl;
    for(int i=1;i<=h.index;i++)
    {
        cout<<h.arr[i]<<" ";
    }
    cout<<endl;
}