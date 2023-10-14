// // Right to Left  Searching

// #include<iostream>
// using namespace std ;

// void lastOccChar(string str,char key,int lastindex,int& ans)
// {
//     if(lastindex<0)
//     return;
    
//     if(str[lastindex]==key)
//     {
//         ans = lastindex;
//         return;
//     }

//     lastOccChar(str,key,lastindex-1,ans);
// }
// int main()
// { 
//    string str = "abbdfc";

//    int lastindex =str.length()-1;
//    char key = 'b';
//    int ans; 
//    lastOccChar(str,key,lastindex,ans);

//    cout<<"Answer is: "<<ans;
// }

// CPP program to find position of a character
// in a given string.

  
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[] = "My name is ayush";
	char* ch = strchr(str, 'a');
	cout << ch - str + 1;
	return 0;
}
