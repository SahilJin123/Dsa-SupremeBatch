#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
template<typename T>
using namespace std ;

class Graph{
    public:
    unordered_map<T,list<T> > adjList;
    
    void addEdge(T u ,T v,bool direction)
    {
        // 0-> undirectional
        // 1-> directional
        
        adjList[u].push_back(v);
        if(direction==0)
        {
            adjList[v].push_back(u);
        }
    }


   void PrintAdjacencyList()
   {
        for (auto node : adjList)
        {
            cout<<node.first<<" -> ";
            for (auto neighbours:node.second)
            {
                cout<<neighbours<<" ";
            }
            cout<<endl;
        }
    
   }
    
};
int main()
{

    Graph<int> g;

    // Undirected Edges
    // g.addEdge(0,1,0);
    // g.addEdge(0,2,0);
    // g.addEdge(1,2,0);
    // g.PrintAdjacencyList();

    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,2,1);
    g.PrintAdjacencyList();
}