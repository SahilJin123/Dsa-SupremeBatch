#include<iostream>
#include<vector>
using namespace std;

int main()
{
   string s = "sahil";

   vector<string> count;

   for(int i=0;i<s.length();i++)
   {
    for(int length = 1;length<=s.length()-i;length++)
    {
        string sample = s.substr(i,length);
        count.push_back(sample);
    }
   }

   for(int i=0;i<count.size();i++)
   {
    cout<<count[i]<<endl;
   }

}