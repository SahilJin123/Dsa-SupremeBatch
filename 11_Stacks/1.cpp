#include<iostream>
#include<stack>
#include <stdlib.h> 
using namespace std ;

int main()
{
    // creation
    stack<int> s;

    // insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // remove
    s.pop();

    //Check element at the top
    cout<<"Element at the top is: "<<s.top()<<endl;

    // Size
    cout<<"Size of stack is: "<<s.size()<<endl;

    if(s.empty())
    {
        cout<<"Stack is empty"<<endl;
    }else{
        cout<<"Stack is Not empty"<<endl;
    }


    // Printing of stack

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
}