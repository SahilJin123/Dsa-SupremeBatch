#include<iostream>
#include<vector>
using namespace std ;


void solveMaze(int maze[3][3],int row,int col,int srcx,int srcy,
                vector<vector<bool>>& visited,vector<string>& path,
                string output )
{
    // Base case :- Hum destination pe pohanch gaye
    if(srcx ==row -1 && srcy==col-1)
    {
        path.push_back(output);
        return;
    }
    
    // Down
    if(srcx+1<row && maze[srcx+1][srcy]==1 && visited[srcx+1][srcy]==0)
    {
        visited[srcx+1][srcy]=1;
        // output.push_back('D');
        solveMaze(maze,row,col,srcx+1,srcy,visited,path,output + 'D');
        visited[srcx+1][srcy]=0;
    }
    // Left
    if(srcy-1>0 && maze[srcx][srcy-1]==1 && visited[srcx][srcy-1]==0)
    {
        visited[srcx][srcy-1]=1;
        // output.push_back('L');
        solveMaze(maze,row,col,srcx,srcy-1,visited,path,output+'L');
        visited[srcx][srcy-1]=0;
    }
    // Right
    if(srcy+1<col && maze[srcx][srcy+1]==1 && visited[srcx][srcy+1]==0)
    {
        visited[srcx][srcy+1]=1;
        // output.push_back('R');
        solveMaze(maze,row,col,srcx,srcy+1,visited,path,output+'R');
        visited[srcx][srcy+1]=0;
    }
    // Up
    if(srcx-1<row && maze[srcx-1][srcy]==1 && visited[srcx-1][srcy]==0)
    {
        visited[srcx-1][srcy]=1;
        // output.push_back('U');
        solveMaze(maze,row,col,srcx-1,srcy,visited,path,output+'U');
        visited[srcx-1][srcy]=0;
    }

}

int main()
{
   int maze[3][3] = {{1,0,0},{1,1,0},{1,1,1}};

   int rows = 3;
   int cols = 3;

   vector<vector<bool>> visited(rows,vector<bool>(cols,false));

//    src ki value ko true mark kardenge

    visited[0][0] =true;

    vector<string> path;
    string output = "";

    solveMaze(maze,rows,cols,0,0,visited,path,output );

    for(auto it :path)
    {
        cout<<it<<endl;
    }
}