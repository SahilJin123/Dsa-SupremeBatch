#include<iostream>
using namespace std ;

bool cmpstring(string a,string b)
{
    if(a.length()!=b.length())
    return false;
    else{
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }
    }

    return true;
}
int main()
{
   string a ="love";
   string b="love";
   bool ans = cmpstring(a,b);
   cout<<"Ans: "<<ans;
}