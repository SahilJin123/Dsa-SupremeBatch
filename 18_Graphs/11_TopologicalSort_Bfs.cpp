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

   void TopoLogicalSortBfs(int n,vector<int>& ans)
   {
        queue<int> q;
        unordered_map<int,int> indegree;

        for(auto i : adjList)
        {
            // int src = i.first;
            for(auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }

        //  put all the nodess inside queue which has indegree = 0

        for (int i = 0;i< n; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        // bfs logic

        while (!q.empty())
        {
            int fnode = q.front();
            q.pop();

            ans.push_back(fnode);

            for(auto neighbour:adjList[fnode])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                {
                    q.push(neighbour);
                }
            }
        }
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

    // stack<int> ans;
    // unordered_map<int,bool> isvisited;
    // int src = 0;
    // g.TopologicalSortDfs(src,isvisited,ans);

    // cout<<"Printing TopoLogical Sort : ";
    // while (!ans.empty())
    // {
    //     cout<<ans.top()<<" ";
    //     ans.pop();
    // }

    vector<int> ans;
    g.TopoLogicalSortBfs(n,ans);
    cout<<"Printing Topological Sort"<<endl;

    for(auto it: ans)
    {
        cout<<it<<" ";
    }

}