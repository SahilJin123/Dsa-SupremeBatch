#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std ;
void printarray(vector<vector<char>>& board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool isSafe(int row,int col,vector<vector<char>>& board,int n)
{
//   check karna hai ,kya main current cell [row,col] pe queen rakh sakta hu ya nahi
    int i = row;
    int j = col;

    // check row
    while(j>=0)
    {
        if(board[i][j]=='Q')
        {   
            return false;
        }
        j--;
    }
    
    // CHeck upperleft Diagnol
    i=row;
    j=col;
    
    while(i>=0 && j>=0)
    {
        if(board[i][j]=='Q')
        {
            return false;
        };
        i--;
        j--;
    }

    // Check Bottomleft Diagnol
    i=row;
    j=col;
    while(i< n && j>=0)
    {
        if(board[i][j]=='Q')
        {
            return false;
        };
        i++;
        j--;
    }


    // Kahin pe bhi quuen nahi milli 
     
     return true;
}
void solve( vector<vector<char>>& board,int col,int n)
{
    // Base case
    if(col>=n)
    {
        printarray(board);
        return;    
    }

    // ek case solve karna hai baaki recursion sambhal lega
    for(int row=0;row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            // rakh do queen agar condition satisfy hooti hai
            board[row][col]='Q';
            // recursive call
            solve(board,col+1,n);
            // backtracking 
            board[row][col]='-';
        }
    }

}
int main()
{
   int n;
   cout<<"Enter the number of queens"<<endl;
   cin>>n;
   vector<vector<char>> board(n,vector<char>(n,'-'));
   int col =0;
   solve(board,col,n);
}