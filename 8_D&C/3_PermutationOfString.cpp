#include<iostream>
#include<vector>
using namespace std ;

void printPermutations(string& str,int index,vector<string>&ans)
{   
    // Base case
      if(index>=str.length())
    {
        ans.push_back(str);
        return;
    }

    // Swapping 
    for(int j=index;j<str.length();j++)
    {   
        // Swap
        swap(str[index],str[j]);
        // Recursion Call
        printPermutations(str,index+1,ans);
        // backtracking -> to recreate the orignal input
         swap(str[index],str[j]);
    }
}
int main()
{
    string str = "abc";
    vector<string>ans;
    int index =0;
    printPermutations(str,index,ans);

    for(auto it:ans)
    {
        cout<<it<<endl;
    }
}