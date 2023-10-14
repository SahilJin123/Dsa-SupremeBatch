#include<iostream>
#include<vector>
using namespace std ;

void checkKey(string str,int n,int index,char Key,vector<int>& ans)
{
    if(index>=n)
    return;

    if(str[index]== Key )
    {   
        // cout<<"Found at:"<<index<<endl;
        ans.push_back(index);
    }
     checkKey(str,n,index+1,Key,ans);
}
int main()
{
    string str = "lovebabbar";
    int n = str.length(); 
    vector<int> ans; 
    char Key = 'b';
    int i = 0;
    checkKey(str,n,i,Key,ans);
    cout<<"Printing Answer"<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }   
}