#include<iostream>
#include<vector>
using namespace std ;

void  permutations(string& str,int index,vector<string>& ans)
{
    if(index>=str.length())
    {
        ans.push_back(str);
        return;
    }

    for(int j =index;j<str.size();j++)
    {
        swap(str[index],str[j]);
        permutations(str,index+1,ans);
        swap(str[index],str[j]);
    }
}

int main()
{
    string str = "abc";
    vector<string> ans;
    int index =0;
    permutations(str,index,ans);

    for(auto it : ans)
    {
        cout<<it<<" ";
    }
}

