#include<iostream>
// #include<bits/stdc++.h>
using namespace std ;

class deque{

    public:
    int *arr;
    int size;
    int front ;
    int rear;

    deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

        void pushRear(int data)
    {
        if((front - rear == 1) || (rear-front == size-1) )      //front-1% size-1

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
        }else{
            rear++;
            arr[rear] = data;
        }
    }

    void pushFront(int data)
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
        else if(rear < size-1 && front==0)
        {
            front = size-1;
            arr[front] = data;
        }else{
            front--;
            arr[front] = data;
        }
    }

     void popFront()
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

    void popRear()
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
        }else if(rear==0 )
        {
            rear = size -1;
        }else{
            rear--;
        }
        
    }

    void print()
    {
        for (int i = 0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    deque p(10);
    p.print();

    p.pushRear(10);
    p.pushRear(20);
    p.pushRear(30);
    p.pushRear(40);
    p.pushRear(50);
    p.pushRear(60);
    p.pushRear(70);
    p.pushRear(80);
    // p.pushRear(90);
    // p.pushRear(100);
    p.print();
}