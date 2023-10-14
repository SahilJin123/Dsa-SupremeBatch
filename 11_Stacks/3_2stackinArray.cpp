#include<iostream>
using namespace std;

class stack{

    private:
    int *arr;
    int size;
    int top1;
    int top2;

    public:
    stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1=-1;
        top2 = size;
    }

    void push1(int data)
    {
        if(top2-top1==1)
        {
          cout<<"overflow in Stack 1 "<<endl;
        }
        else{
            top1++;
            arr[top1]=data;
        }
    }

    void push2(int data)
    {
        if(top2-top1==1)
        {
          cout<<"overflow in Stack 2"<<endl;
        }
        else{
            top2--;
            arr[top2]=data;
        }
    }

    void pop1()
    {
        if(top1==-1)
        {
            cout<<"Underflow in Stack 1"<<endl;
        }else{
            top1--;
        }
    }
    void pop2()
    {
        if(top2==size)
        {
            cout<<"Underflow in Stack 2"<<endl;
        }else{
            top2++;
        }
    }
};
int main()
{
    stack s(10);
    // insertion
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);


    s.push2(110);
    s.push2(210);
    s.push2(301);
    s.push2(401);

    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
}