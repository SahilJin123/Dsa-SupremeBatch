#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
#include<queue>
using namespace std ;
template<typename T>

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

   void BfS(int src,unordered_map<int,bool>& isvisited)
   {
        queue<int> q;
        q.push(src);

        isvisited[src] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            cout<<frontNode<<" ";

            // insert NeighBours
            for(auto neighbour:adjList[frontNode])
            {
                if(isvisited[neighbour]==false)
                {
                    q.push(neighbour);
                    isvisited[neighbour] = true;
                }
            }

        }
   }

   void DFS(int src,unordered_map<int,bool>& isvisited)
   {
        cout<<src<<" ";
        isvisited[src] = true;

        for(auto neighbour : adjList[src])
        {
            if(!isvisited[neighbour])
            {
                DFS(neighbour,isvisited);
            }
        }
   }

   void TopologicalSortDfs(int src,unordered_map<int,bool>& isvisited,stack<int>& ans)
   {

        isvisited[src] = true;

        for(auto neighbour : adjList[src])
        {
            if(!isvisited[neighbour])
            {
                TopologicalSortDfs(neighbour,isvisited,ans);
            }
        }

        ans.push(src);
   }

    
};
int main()
{

    Graph<int> g;
    int n = 8;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1); 
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1); 
    g.addEdge(6,7,1);

    g.PrintAdjacencyList();
    cout<<endl;

    stack<int> ans;
    unordered_map<int,bool> isvisited;
    int src = 0;
    g.TopologicalSortDfs(src,isvisited,ans);

    cout<<"Printing TopoLogical Sort : ";
    while (!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    


    
}