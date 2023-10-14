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


    
};
int main()
{
    Graph g;

    g.addEdge(6,3,2,0);
    g.addEdge(6,5,9,0);
    g.addEdge(6,1,14,0);
    g.addEdge(1,3,9,0);
    g.addEdge(1,2,7,0);
    g.addEdge(2,3,10,0);
    g.addEdge(2,4,15,0);
    g.addEdge(3,4,11,0);
    g.addEdge(5,4,6,0);


    // g.printAdjList();

    g.Dijkistra(6,4);



}