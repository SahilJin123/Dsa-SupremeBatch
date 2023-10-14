#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>   
using namespace std ;
int main()
{
    // Creation
    unordered_map<string,int> m;
    

    // insertion 
    pair<string,int> p = make_pair("Scorpio",9);
    m.insert(p);

    pair<string,int> p2("Alto",2);
    m.insert(p2);

    m["fortuner"] = 10;

    // Access

    cout<<m["Alto"]<<endl;

    cout<<m.at("Scorpio")<<endl;


    // Search :- Tells if particular key exist or not if yes print 1 else it print 0
    cout<<m.count("xcorpio")<<endl;

    if(m.find("fortuner") != m.end())
    {
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }


    // SIze of map
    cout<<m.size()<<endl; 
    cout<<m["Hammer"]<<endl;
    m["bammer"];
    cout<<m.size()<<endl;


    cout<<"Printing all Enteries: "<<endl;

    for(auto i: m)
    {
        cout<<i.first<<" -> "<<i.second<<endl;
    }
}