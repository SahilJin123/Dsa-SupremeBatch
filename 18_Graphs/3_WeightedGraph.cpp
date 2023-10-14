#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std ;

class Graph{
    public:
    unordered_map<int,list<pair<int,int>> > adjList;

    void addEdge(int u,int v,int weight,bool direction)
    {

        adjList[u].push_back({v,weight});
        if(direction==0)
        {
            adjList[v].push_back({u,weight});
        }
    }

    void PrintAdjacencyList()
    {
        for(auto node : adjList)
        {
            cout<<node.first<<" -> ";
            for(auto it:node.second)
            {
                cout<<"("<<it.first<<","<<it.second<<") ";
            }
            cout<<endl;
        }
    }

};
int main()
{
    Graph g;
    g.addEdge(0,1,9,1);
    g.addEdge(0,2,5,1);
    g.addEdge(1,2,3,1);
    g.PrintAdjacencyList();
}