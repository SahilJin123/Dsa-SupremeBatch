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

    bool checkCyclicDirectedGraphUsingDFS(int src,unordered_map<int,bool>& isvisited,unordered_map<int,bool>& Dfsvisited )
    {
        isvisited[src] = true;
        Dfsvisited[src] = true;

        for(auto neighbour : adjList[src])
        {
            if(!isvisited[neighbour])
            {
                bool aagekaanswer = checkCyclicDirectedGraphUsingDFS(neighbour,isvisited,Dfsvisited);
                if(aagekaanswer)
                return true;
            }

            if(isvisited[neighbour] && Dfsvisited[neighbour])
            return true;
        } 

        // Yahi Pe galati Karenge
        Dfsvisited[src] = false;
        return false;
    }
    
};
int main()
{

    Graph<int> g;
    int n = 5;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1); 
    g.addEdge(3,1,1);


    int src = 0;
    bool ans = false;
    unordered_map<int,bool> isvisited;
    
    unordered_map<int,bool> Dfsvisited;
    for (int i = 0; i < n; i++)
    {
        if(!isvisited[i])
        {
            ans = g.checkCyclicDirectedGraphUsingDFS(src,isvisited,Dfsvisited);
            if(ans==true)
            break;
        }
    }
    
    if(ans)
    {
        cout<<"Cycle is Present";
    }else{
        cout<<"Cycle is not Present";
    }


    // cout<<"Printing BFS of the Graph : "<<endl;
    // unordered_map<int,bool> isvisited;
    // for(int i =0;i<n;i++)
    // {
    //     if(!isvisited[i])
    //     {
    //         g.BfS(src,isvisited);
    //     }
    // }

    // cout<<endl<<"Printing DFS of the Graph : "<<endl;
    // unordered_map<int,bool> isvisited2;
    // for(int i =0;i<n;i++)
    // {
    //     if(!isvisited2[i])
    //     {
    //         g.DFS(src,isvisited2);
    //     }
    // }
}