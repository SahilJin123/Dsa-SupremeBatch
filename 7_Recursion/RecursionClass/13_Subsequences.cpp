#include<iostream>
#include<vector>
using namespace std ;

void subsequence(string str,string output,int index,int &count,vector<string>& ans)
{
    if(index>=str.length())
    {   
        count++;
        ans.push_back(output);
        // cout<<output<<endl;
         return;
    }
    
    // exclude Case
    subsequence(str,output,index+1,count,ans);
    
    // include
    output.push_back(str[index]);
    subsequence(str,output,index+1,count,ans);
}
int main()
{
    string str = "Sahil";
    // int n = str.length();
    string output ="";
    int count =0;
    int index = 0;
    vector<string> ans;
    subsequence(str,output,index,count,ans);
    // cout<<count<<endl;

    for(auto it :ans)
    {   
        cout<<it<<endl;
    }

}