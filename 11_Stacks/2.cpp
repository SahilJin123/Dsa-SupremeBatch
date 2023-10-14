#include<iostream>
#include<vector>
using namespace std;

class stack
{   
    private:
    int *arr;
    int top;
    int size; //yeh total array ke size ko batata hai total no. of element ko nahi batata
    public:
    stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    // Functions

    void push(int data)
    {
        if(size-top>1)
        {
            // Space available
            // insert
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
       if(top==-1)
       {
        // stack is empty
        cout<<"Stack Underflow, can't delete element"<<endl;
       }
       else{
        top--;
       }   
    }

    int peek()
    {
        if(top==-1)
        {
           cout<<"Stack Underflow, No element in Stack "; 
           return -1;
        }
        else{
            return arr[top];
        }
    }

    int getsize()
    {
        return (top+1);
    }

    bool empty()
    {
        if(top==-1)
        {
            return true;
        }else{
            return false;
        }
    }
};
int main()
{
    stack s(10);
    // insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.empty())
    {
        cout<<s.peek()<<endl;
        s.pop();
    }


}