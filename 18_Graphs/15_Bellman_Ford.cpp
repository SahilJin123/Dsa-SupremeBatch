#include<iostream>
// #include<bits/stdc++.h>
#include<unordered_map>
#include<queue>
#include<list>
#include<set>
#include<limits.h>
using namespace std ;

class Graph{
    public:
    unordered_map<int , list<pair<int,int > > > adjList;

    void addEdge(int u,int v,int wt,int direction)
    {
        adjList[u].push_back({v,wt});
        if(direction==0)
        {
            adjList[v].push_back({u,wt});
        }
    }

    void printAdjList() {
		for(auto i: adjList) {
			cout << i.first <<"-> ";
			for(auto j: i.second) {
				cout << "(" << j.first<<", "<<j.second<<"), ";
			}
			cout << endl;
		}
	}

    void Dijkistra(int src,int dest)
    {
        int n = adjList.size();
        vector<int> distance(n+1,INT_MAX);
        set<pair<int,int>> st;
        distance[src] = 0;
        st.insert({0,src});

        while(!st.empty())
        {
            // St.begin returns the iterator
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;
            st.erase(st.begin());

            for(auto nbr : adjList[node])
            {
                if(distance[nbr.first]>nodeDistance + nbr.second)
                {
                    // find entery  in set
                    auto result = st.find({distance[nbr.first],nbr.first});

                    // if found then remove
                    if(result!=st.end())
                    {  
                        st.erase(result);
                    }
                    // updation of distance in array and set
                    distance[nbr.first] = nodeDistance + nbr.second;
                    st.insert({distance[nbr.first],nbr.first});

                }
            }
        }

        for(int i=0;i<n+1;i++)
        {
            cout<<distance[i]<<" ";
        }

    }
    
    void BellmanFord(int src,int n)
    {
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
    
        for(int i=1;i<n;i++)
        {
            for(auto t : adjList)
            {
                for(auto nbr : t.second)
                {
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    if(dist[u]!=INT_MAX && dist[u] + wt < dist[v] )
                    {
                        dist[v] = dist[u] + wt ;
                    }
                }
            }
        }


        //  To check for negative cycle
        bool negativecycle = false;
        for(auto t : adjList)
        {
            for(auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                if(dist[u]!=INT_MAX && dist[u] + wt < dist[v] )
                {
                    negativecycle = true;
                    break;
                }
            }
        }

        if(negativecycle)
        {
            cout<<"The Negative Cycle is detected"<<endl;
        }else{
            cout<<"The Negative Cycle is detected"<<endl;
        }



        cout<<"Printing Distance Array :"<<endl;
        for(auto it : dist)
        {
            cout<<it<<" ";
        }
    }

    void FloydWarshal(int n)
    {
        vector<vector<int>> dist(n,vector<int>(n,100000));
        for(int i=0;i<n;i++)
        {
            dist[i][i] = 0;
        }
         
        //  graph k according distance insert kardiye 
         for(auto t : adjList)
         {
            for(auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second; 
                dist[u][v] = wt;
            }
         }

         for(int helper = 0;helper<n;helper++)
         {
            for(int src = 0;src<n;src++)
            {
                for(int dest = 0;dest<n;dest++)
                {
                    dist[src][dest] =  min(dist[src][dest],dist[src][helper] + dist[helper][dest]);
                }
            }
         }

         cout<<"Printing the Distance"<<endl;
         for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g;

    // g.addEdge(6,3,2,0);
    // g.addEdge(6,5,9,0);
    // g.addEdge(6,1,14,0);
    // g.addEdge(1,3,9,0);
    // g.addEdge(1,2,7,0);
    // g.addEdge(2,3,10,0);
    // g.addEdge(2,4,15,0);
    // g.addEdge(3,4,11,0);
    // g.addEdge(5,4,6,0);


    // // g.printAdjList();

    // g.Dijkistra(6,4);

    // *********************Bellman Ford *************************
    // g.addEdge(0,1,-1,1);
    // g.addEdge(0,2,4,1);
    // g.addEdge(1,2,3,1);
    // g.addEdge(1,3,2,1);
    // g.addEdge(1,4,2,1);
    // g.addEdge(3,1,1,1);
    // g.addEdge(3,2,5,1);
    // g.addEdge(4,3,-3,1);
 
    // g.BellmanFord(0,5);

    g.addEdge(0,1,3,1);
    g.addEdge(0,3,5,1);
    g.addEdge(1,0,2,1);
    g.addEdge(1,3,4,1);
    g.addEdge(2,1,1,1);
    g.addEdge(3,2,2,1);
    // g.addEdge(3,2,5,1);
    // g.addEdge(4,3,-3,1);
 
    g.FloydWarshal(4);

}