#include<iostream>
#include<vector>
using namespace std ;

bool issafe(int x,int y,int row,int col,int arr[][3],vector<vector<bool>>& visited)
{
    if((x>=0 && x<row) && (y>=0 && y<col) && visited[x][y]==0 && arr[x][y]==1 )
    return true;

    return false;
}

void solveMaze(int maze[3][3],int row,int col,int srcx,int srcy,
                vector<vector<bool>>& visited,vector<string>& path,
                string output )
{
    // Base case :- Hum destination pe pohanch gaye
    if(srcx ==row-1 && srcy==col-1)
    {
        path.push_back(output);
        return;
    }
    
    // Down
    if(issafe(srcx+1,srcy,row,col,maze,visited))
    {
        visited[srcx+1][srcy]=1;
        // output.push_back('D');
        solveMaze(maze,row,col,srcx+1,srcy,visited,path,output + 'D');
        visited[srcx+1][srcy]=0;
    }
    // Left
    if(issafe(srcx,srcy-1,row,col,maze,visited))
    {
        visited[srcx][srcy-1]=1;
        // output.push_back('L');
        solveMaze(maze,row,col,srcx,srcy-1,visited,path,output+'L');
        visited[srcx][srcy-1]=0;
    }
    // Right
    if(issafe(srcx,srcy+1,row,col,maze,visited))
    {
        visited[srcx][srcy+1]=1;
        // output.push_back('R');
        solveMaze(maze,row,col,srcx,srcy+1,visited,path,output+'R');
        visited[srcx][srcy+1]=0;
    }
    // Up
    if(issafe(srcx-1,srcy,row,col,maze,visited))
    {
        visited[srcx-1][srcy]=1;
        // output.push_back('U');
        solveMaze(maze,row,col,srcx-1,srcy,visited,path,output+'U');
        visited[srcx-1][srcy]=0;
    }

}

int main()
{
   int maze[3][3] = {{1,0,0},{1,1,0},{1,1,0}};

   if(maze[0][0]==0)
   {
    cout<<"No Path Exists";
    return 0;
   }
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

    if(path.size()==0)
    {
        cout<<"No Path exists";
    }

    return 0;
}