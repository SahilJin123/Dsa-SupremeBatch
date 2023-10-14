#include<iostream>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std ;


unordered_map<int,bool> rowCheck;
unordered_map<int,bool> uppelLeftDiagnolCheck;
unordered_map<int,bool> bottomLeftDiagnolCheck;

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
    if(rowCheck[row]==true)
    return false;

    if(uppelLeftDiagnolCheck[n-1 + col-row]==true)
    return false;

    if(bottomLeftDiagnolCheck[col+row]==true)
    return false;

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
            rowCheck[row] =true;
            uppelLeftDiagnolCheck[n-1+col-row] = true;
            bottomLeftDiagnolCheck[col+row] = true;
            // recursive call
            solve(board,col+1,n);
            // backtracking 
            board[row][col]='-';
            rowCheck[row] =false;
            uppelLeftDiagnolCheck[n-1+col-row] = false;
            bottomLeftDiagnolCheck[col+row] = false;
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