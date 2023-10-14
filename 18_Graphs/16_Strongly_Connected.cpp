#include<iostream>

#include<bits/stdc++.h>
#include<unordered_map>
#include<list>
#include<stack>
#include<queue>
using namespace std ;

class Graph{
    public:
    unordered_map<int,list<int>> adjList;

    void addEdge(int u,int v,int direction)
    {
        adjList[u].push_back(v);

        if(direction==0)
        {
            adjList[v].push_back(u);
        }
    }

    void toposort(int src,unordered_map<int,bool>& isvisited,stack<int>& s)
    {
        isvisited[src] = true;

        for(auto nbr : adjList[src])
        {
            if(!isvisited[nbr])
            {
                toposort(nbr,isvisited,s);
            }
        }

        s.push(src);
    }

    void dfs(int src,unordered_map<int,bool>& isvisited,unordered_map<int,list<int>> adjNew)
    {
        isvisited[src] = true;
        cout<<src<<" ,";
        for(auto nbr : adjNew[src])
        {
            if(!isvisited[nbr])
            {
                dfs(nbr,isvisited,adjNew);
            }
        }
    }

    int countSCC(int n)
    {
        stack<int> s;
        unordered_map<int,bool> isvisited;

        for(int i=0;i<n;i++)
        {
            if(!isvisited[i])
            {
                toposort(i,isvisited,s);
            }
        }
        
        unordered_map<int,list<int>> ReverseadjList;

        for(auto node : adjList)
        {
            int fnode = node.first;
            auto listnode = node.second;

            for(int nbr : listnode)
            {
                ReverseadjList[nbr].push_back(fnode);
            }
        }

        // traverse using Dfs
        int count = 0;
        isvisited.clear();
        while(!s.empty())
        {
            int node = s.top();
            s.pop();

            if(!isvisited[node])
            {
                cout<<"Printing "<<count+1<<"th SCC ";
                dfs(node,isvisited,ReverseadjList);
                cout<<endl;
                count++;
            }
        }
        
        return count;

    }
};
int main()
{
    Graph g;

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,0,1);
    g.addEdge(2,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,4,1);
    g.addEdge(6,7,1);
    // g.addEdge(,,1);
    // g.addEdge(,,1);

    int ans = g.countSCC(8); 
    cout<<ans;
}