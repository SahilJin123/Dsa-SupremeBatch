#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class Heap{
    public:
    int *arr;
    int size;
    int index;
    Heap(int size)
    {
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
};
int main()
{
    Heap h(10);
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.index = 5;
    cout<<"Printing The Heap :"<<endl;
    for(int i=1;i<=h.index;i++)
    {
        cout<<h.arr[i]<<" ";
    }
    cout<<endl;
    
    h.insert(110);
    for(int i=1;i<=h.index;i++)
    {
        cout<<h.arr[i]<<" ";
    }
}