#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std ;
int main()
{
    int n;
    cout<<"Enter the Number of Nodes : "<<endl;
    cin>>n;

    vector<vector<int> >adj(n,vector<int>(n,0));

    int e;
    cout<<"Enter the Number of Edges : "<<endl;
    cin>>e;

    for (int i = 0; i < e; i++)
    {
        int u,v ;
        cout<<"Enter the Value of U :"<<endl;
        cin>>u;
        cout<<"Enter the Value of V :"<<endl;
        cin>>v;

        adj[u][v] =1;
        adj[v][u] =1;
    } 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    
    

}