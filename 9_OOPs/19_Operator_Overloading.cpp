#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class Param{
    public:
    int val;

    int operator+(Param &obj)
    {
        int value1= this->val;
        int value2 = obj.val;
        return value2-value1;
    }
};

int main()
{
    Param obj1,obj2;
    obj1.val = 7;
    obj2.val = 2;

    // This Should print the difference between them
    cout<<obj1 + obj2;
}