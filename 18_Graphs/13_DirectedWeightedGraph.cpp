#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<limits.h>
using namespace std;


class graph {
	public:
	unordered_map<int, list<pair<int,int> > > adjList;

	void addEdge(int u, int v, int wt, bool direction) {
		//direction = 1 -> undirected graph
		//direction => 0 -> directed graph;
		adjList[u].push_back({v,wt});
		if(direction == 1) {
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

	void shortestPathBfs(int src, int dest){
		queue<int> q;
		unordered_map<int,bool> visited;
		unordered_map<int,int> parent;

		//inital steps for src
		q.push(src);
		visited[src] = 1;
		parent[src] = -1;

		while(!q.empty()) {
			int fNode = q.front();
			q.pop();

			for(auto nbr: adjList[fNode]) {
				if(!visited[nbr.first]) {
					q.push(nbr.first);
					visited[nbr.first] = 1;
					parent[nbr.first] = fNode;
				}
			}
		}

		//store path in ans, after traversing in the parent array
		vector<int> ans;
		int node = dest;
		while(node != -1) {
			ans.push_back(node);
			node = parent[node];
		}

		reverse(ans.begin(), ans.end());

		cout << "printing ANS: " <<endl;
		for(auto i: ans) {
			cout << i<<", ";
		}
		cout << endl;
		
	}


    void TopologicalSortDfs(int src,unordered_map<int,bool>& isvisited,stack<int>& s)
    {
        isvisited[src] = true;

        for(auto neighbour : adjList[src])
        {
            if(!isvisited[neighbour.first])
            {
                TopologicalSortDfs(neighbour.first,isvisited,s);
            }
        }
        s.push(src);
    }

    void ShortestPathDfs(int dest,stack<int>& topoOrder)
    {
		int n = topoOrder.size();
        vector<int> distance(n,INT_MAX);

        int src = topoOrder.top();
        // topoOrder.pop();
        distance[src] = 0;

		// for(auto nbr : adjList[0])
		// {
		// 	distance[nbr.first] = min(distance[nbr.first],distance[0] + nbr.second); 
		// }
        while (!topoOrder.empty())
        {
             int topElement = topoOrder.top();
             topoOrder.pop();

			 if(distance[topElement]!=INT_MAX)
			 {
				for(auto nbr : adjList[topElement])
				{
				  distance[nbr.first] = min(distance[nbr.first],distance[topElement] + nbr.second); 
				}
			 }
             
        }

		for(int i=0;i<n;i++)
		{
			cout<<distance[i]<<" ";
		}
        
		// return distance[dest];

    }
    
};
int main()
{
    graph g;
    int n = 8;
    g.addEdge(0,1,5,0);
    g.addEdge(0,2,3,0);
    g.addEdge(2,1,2,0); 
    g.addEdge(1,3,3,0); 
    g.addEdge(2,3,5,0);
    g.addEdge(2,4,6,0);
    g.addEdge(4,3,1,0);
    // g.addEdge(0,5,1,1);
    // g.addEdge(5,4,1,1);
    // g.addEdge(8,4,1,1);
    
    g.printAdjList();
    cout<<endl;
    int src = 0;
    stack<int> topoOrder;
    unordered_map<int,bool> isvisited;
	int dest = 3;
    g.TopologicalSortDfs(src,isvisited,topoOrder);
	g.ShortestPathDfs(dest,topoOrder);
	// cout<<"Shortest Path Distance in Weighted Graph is : "<<shortestpathWeighted<<endl;
    
}