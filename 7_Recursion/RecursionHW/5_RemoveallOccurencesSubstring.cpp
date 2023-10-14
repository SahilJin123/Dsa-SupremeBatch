#include<iostream>
#include<string.h>
using namespace std ;

// void RemoveOccurencesSubstring(string& str,string part)
// {   
//     int found = str.find(part);
    
//     if(found == string::npos)
//      return;

//     str.erase(found,part.length());

//     RemoveOccurencesSubstring(str,part);
// }

// Without erasing the string

void RemoveOccurencesSubstring(string& str,string part)
{   
    int found = str.find(part);
    
    if(found != string::npos)
    {
        string left_part = str.substr(0,found);
        string right_part = str.substr(found+part.length(),str.length());
        str = left_part + right_part ;
        RemoveOccurencesSubstring(str,part);
    }

     return;

}
int main()
{
    string str = "maamaambaa";
    string part = "aa";
     RemoveOccurencesSubstring(str,part);

     cout<<str;
}