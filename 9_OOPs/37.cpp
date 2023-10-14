#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
// local and global variable


int x = 2;  //global variable

void func()
{
    int x = 70;
    cout<<x<<endl;
    ::x = 100;
    cout<<::x<<endl;

}

int main()
{
    int x =20;
    cout<<x<<endl;
    cout<<::x<<endl; // way to access global variable with ::

    {
        int x = 50;
        cout<<::x<<endl;
    }

    func();
    return 0;
}