#include<iostream>
#include<vector>
using namespace std ;

bool palindrome(string str,int start,int end)
{
    if(start>=end)
    return true;
    
    if(str[start]!=str[end])
    return false;
    // Baaki recursion sambhal lega
    palindrome(str,start+1,end -1);
}
int main()
{
    string str = "maam";

    int start =0;
    int end = str.length()-1;
    bool ans = palindrome(str,start,end);

    if(ans)
    cout<<"Palindrome";
    else
    cout<<"Not Palindrome";
}