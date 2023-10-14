#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    char ch[10] = "Sahil";
    char* c = ch;

    cout<<ch<<endl;
    cout<<&ch<<endl;
    cout<<ch[0]<<endl;

    cout<<c<<endl;
    cout<<*c<<endl;
    cout<<&c<<endl;
    cout<<c[0]<<endl;

    // char name[10] = "SherBano";
    // char *cptr = &name[0];
    // cout<<cptr<<endl;
    // cout<<*(cptr+3)<<endl;
    // cout<<cptr+2<<endl;
    // cout<<cptr+8<<endl;  NUll Print kardega

} 

