#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std ;

class queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        if((front - rear == 1) || (rear-front == size-1) )
        {
            cout<<"Q is full";
            return;
        }else if(front==-1 && rear==-1)
        {   
            // First Element Entry
            front=0;
            rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front!=0)
        {
            rear = 0;
            arr[rear] = data;
            // rear++;
        }else{
            rear++;
            arr[rear] = data;
        }
    }

    void pop()
    {   
        // Empty Check
        if(front==-1)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }else if(front==rear)
        {
            front = -1;
            rear = -1;
        }else if(front == size -1 )
        {
            front = 0;
        }else{
            front++;
        }
        
    }
};
int main()
{

}