#include<iostream>
// #include<bits/stdc++.h>
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
        front =0;
        rear =0;
    }

    void push(int data)
    {
        if(rear==size)
        {
            cout<<"Queue is full"<<endl;
        }else{
            arr[rear]=data;
            rear++;
        }
    }

    void pop()
    {
        if(front==rear)
        {
            cout<<"Queue is Empty";
        }
        else{ 
            arr[front] = -1;
            front++;
            if(front ==rear)
            {
                front=0;
                rear=0;
            }
        }
    }

    int getfront()
    {
        if(front==rear)
        {
            cout<<"Queue is Empty";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty()
    {
         if(front==rear)
        {
            return true;
        }
        return false;
    }
    int getSize()
    {
        return rear-front;
    }
};
int main()
{
    queue q(10);

    q.push(10);
    q.push(10);
    q.push(10);
    q.push(10);
    cout<<q.getfront()<<endl;

    cout<<q.getSize()<<endl;

    cout<<q.isEmpty()<<endl;
}