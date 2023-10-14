// // #include<iostream>
// // #include<bits/stdc++.h>
// // #include<unordered_map>
// // using namespace std ;

// // class Graph{
// //     public:
// //     unordered_map<int,list<int>> adjList;
    
// //     void addEdge(int u,int v,int direction)
// //     {
// //         // 0 -> undirectional
// //         // 1 ->directional
// //         adjList[u].push_back(v);
// //         if(direction==0)
// //         {
// //             adjList[v].push_back(u);
// //         }
// //     }

// //     void PrintAdjacencyList()
// //     {
// //         for(auto node : adjList)
// //         {
// //             cout<<node.first<<" -> ";
// //             for(auto it : node.second)
// //             {
// //                 cout<<it<<" ";
// //             }

// //             cout<<endl;
// //         }
// //     }

// //     void bfs(int src)
// //     {
// //         queue<int> q;
// //         q.push(src);

// //         unordered_map<int,bool> isvisited;
// //         isvisited[src] = true;

// //         while (!q.empty())
// //         {
// //             int fnode = q.front();
// //             q.pop();
// //             cout<<fnode<<" ";
// //             for(auto neighbour : adjList[fnode])
// //             {
// //                 if(!isvisited[neighbour])
// //                 {
// //                     q.push(neighbour);
// //                     isvisited[fnode] = true;
// //                 }
// //             }
// //         }
        
// //     }

// //     void dfs(int src,unordered_map<int,bool>& isvisited)
// //     {
// //         cout<<src<<" ";
// //         isvisited[src] = true;

// //         for(auto neighbour : adjList[src])
// //         {
// //             if(!isvisited[neighbour])
// //             {
// //                 dfs(neighbour,isvisited);
// //             }
// //         }
// //     }

// //     bool cycleDetectionBfs(int src)
// //     {
// //         unordered_map<int,bool> isvisited;
// //         unordered_map<int,int> parent;

// //         queue<int> q;
// //         q.push(src);
// //         isvisited[src] = true;
// //         parent[src] = -1;

// //         while(!q.empty())
// //         {
// //             int fnode = q.front();
// //             q.pop();

// //             for(auto nbr : adjList[fnode])
// //             {
// //                 if(!isvisited[nbr])
// //                 {
// //                     q.push(nbr);
// //                     isvisited[nbr] = true;
// //                     parent[nbr] = fnode;
// //                 }else{
// //                     if(nbr != parent[fnode])
// //                     {
// //                         cout<<"Cycle is Present"<<endl;
// //                         return true;
// //                     }
// //                 }
// //             }
// //         }
// //         return false;
// //     }

// //     bool cycleDetectionDfs(int src,unordered_map<int,bool>& isvisited,int parent)
// //     {
// //         isvisited[src] = true;

// //         for(auto nbr : adjList[src])
// //         {
// //             if(!isvisited[nbr])
// //             {
// //                 return cycleDetectionDfs(nbr,isvisited,src);
// //             }else{
// //                 if(nbr != parent)
// //                 return true;
// //             }
// //         }

// //         return false;
// //     }

// //     bool cycleDetectionDirectedDfs(int src,unordered_map<int,bool>& isvisited,unordered_map<int,bool>& Dfsvisited)
// //     {
// //         isvisited[src] = true;
// //         Dfsvisited[src] = true;

// //         for(auto nbr : adjList[src])
// //         {
// //             if(!isvisited[nbr])
// //             {
// //                 return cycleDetectionDirectedDfs(nbr,isvisited,Dfsvisited);
// //                 // isvisited[src] = true;
// //                 // Dfsvisited[src] = true;
// //             }else{
// //                 if(Dfsvisited[src]==true)
// //                 {
// //                     return true;
// //                 }else{
// //                     Dfsvisited[src] = false;
// //                 }
// //             }
// //         }
// //         //  ab jabh hum recursive call stack se bahar jayenge toh false mark kardenge
// //         // Dfsvisited[src] = false;
// //         return false;
// //     }

// //     void TopologicalSortDfs(int src,unordered_map<int,bool>& isvisited,stack<int>& ans)
// //     {
// //         isvisited[src] = true;

// //         for(auto nbr : adjList[src])
// //         {
// //             if(!isvisited[nbr])
// //             {
// //                 TopologicalSortDfs(nbr,isvisited,ans);
// //             }
// //         }

// //         ans.push(src);
// //     }

// //     void TopologicalSortBfs(int src,vector<int>& ans)
// //     {
// //         queue<int> q;
// //         unordered_map<int,int> indegree;

// //         for(auto i : adjList)
// //         {
// //             for(auto nbr : i.second)
// //             {
// //                 indegree[nbr]++;
// //             }
// //         }
// //         int n = adjList.size();
// //         for(int i=0; i<n;i++)
// //         {
// //             if(indegree[i]==0)
// //             {
// //                 q.push(i);
// //             }
// //         }

// //         while(!q.empty())
// //         {
// //             int fnode = q.front();
// //             q.pop();

// //             ans.push_back(fnode);

// //             for(auto nbr: adjList[fnode])
// //             {
// //                 indegree[nbr]--;
// //                 if(indegree[nbr]==0)
// //                 {
// //                     q.push(nbr);
// //                 }
// //             }
// //         }
// //     }
// // };
// // int main()
// // {
// //     Graph g;

// //     // Undirected Edges
// //     // int n = 8;
// //     // g.addEdge(0,1,0);
// //     // g.addEdge(1,2,0);
// //     // g.addEdge(1,3,0);
// //     // g.addEdge(3,5,0);
// //     // g.addEdge(3,7,0);
// //     // g.addEdge(7,6,0);
// //     // g.addEdge(7,4,0);

// //     // g.PrintAdjacencyList();
// //     int src = 0;
// //     // // g.bfs(src);
// //     // unordered_map<int,bool> isvisited;
// //     // for(int i =0;i<=n;i++)
// //     // {
// //     //     if(!isvisited[i])
// //     //     {
// //     //         g.dfs(i,isvisited);
// //     //     }
// //     // }

// //     // int n = 5;
// //     // g.addEdge(0,1,0);
// //     // g.addEdge(1,2,0);
// //     // g.addEdge(2,3,0); 
// //     // g.addEdge(3,1,0);

// //     // // int ans = g.cycleDetectionBfs(src);
// //     // unordered_map<int,bool> isvisited;
// //     // int ans = g.cycleDetectionDfs(src,isvisited,-1);

// //     // int n = 5;
// //     // g.addEdge(0,1,1);
// //     // g.addEdge(1,2,1);
// //     // g.addEdge(2,3,1); 
// //     // g.addEdge(1,3,1);


// //     // unordered_map<int,bool> isvisited;
// //     // unordered_map<int,bool> Dfsvisited;
// //     // int ans = g.cycleDetectionDirectedDfs(src,isvisited,Dfsvisited);
// //     // if(ans)
// //     // {
// //     //     cout<<"Cycle is Present"<<endl;
// //     // }else{
// //     //     cout<<"Cycle is Not Present"<<endl;
// //     // }
// //     // g.addEdge(0,1,1);
// //     // g.addEdge(1,2,1);
// //     // g.addEdge(2,3,1); 
// //     // g.addEdge(3,4,1);
// //     // g.addEdge(3,5,1);
// //     // g.addEdge(4,6,1);
// //     // g.addEdge(5,6,1); 
// //     // g.addEdge(6,7,1);

// //     // stack<int> ans;
// //     // unordered_map<int,bool> isvisited;
// //     // g.TopologicalSortDfs(src,isvisited,ans);   
// //     // while(!ans.empty())
// //     // {
// //     //     cout<<ans.top()<<" ";
// //     //     ans.pop();
// //     // }

// //     g.addEdge(2,4,1);
// //     g.addEdge(2,5,1);
// //     g.addEdge(4,6,1); 
// //     g.addEdge(5,3,1);
// //     g.addEdge(3,7,1);
// //     g.addEdge(6,7,1);
// //     g.addEdge(7,0,1); 
// //     g.addEdge(7,1,1);
// //     vector<int> ans;
// //     g.TopologicalSortBfs(2,ans);

// //     for(auto it : ans)
// //     {
// //         cout<<it<<" ";
// //     }
// // }



// #include<iostream>
// #include<unordered_map>
// #include<list>
// #include<queue>
// #include<stack>
// using namespace std ;

// class Graph
// {
//     public:
//     unordered_map<int,list<pair<int,int>>> adjList;
//     void addEdge(int u,int v,int wt,int direction)
//     {
//         adjList[u].push_back({v,wt});
//         if(direction==0)
//         {
//            adjList[v].push_back({u,wt}); 
//         }
//     }

//     void printAdjList() {
// 		for(auto i: adjList) {
// 			cout << i.first <<"-> ";
// 			for(auto j: i.second) {
// 				cout << "(" << j.first<<", "<<j.second<<"), ";
// 			}
// 			cout << endl;
// 		}
// 	}

//     void ShortestPath(int src,int dest,vector<int>& parent)
//     {
//         unordered_map<int,bool> isvisited;
//         queue<int> q;
//         q.push(src);
//         parent[src] = -1;
//         isvisited[src] = true;

//         while (!q.empty())
//         {
//             int fnode = q.front();
//             q.pop();

//             for(auto nbr : adjList[fnode])
//             {
//                 if(!isvisited[nbr.first])
//                 {
//                     q.push(nbr.first);
//                     parent[nbr.first] = fnode;
//                     isvisited[nbr.first] = true;
//                 }
//             }
//         }
        
//     }

//     void TopologicalSortDfs(int src,unordered_map<int,bool>& isvisited,stack<int>& ans)
//     {
//         isvisited[src] = true;

//         for(auto nbr : adjList[src])
//         {
//             if(!isvisited[nbr.first])
//             {
//                 // isvisited[nbr.first] = true;
//                 TopologicalSortDfs(nbr.first,isvisited,ans);
//             }
//         }

//         ans.push(src);
//     }

//     void ShortestPathDfs(int dest,stack<int>& topoOrder)
//     {
//        int n = topoOrder.size();
//        vector<int> distance(n,INT_MAX);
//        int src = topoOrder.top();
//        topoOrder.pop();
//        distance[src] = 0;

//         while(!topoOrder.empty())
//         {
//             for(auto nbr : adjList[src])
//             {
//                     distance[nbr.first] = min(distance[nbr.first],distance[src]+nbr.second); 
//             }
//         }
       
         

//     }
// };
// int main()
// {
//     // Graph g;
//     // g.addEdge(0,1,1,0);
//     // g.addEdge(0,2,1,0);
//     // g.addEdge(0,3,1,0);
//     // g.addEdge(1,4,1,0);
//     // g.addEdge(4,5,1,0);
//     // g.addEdge(2,5,1,0);
//     // g.addEdge(3,6,1,0);
//     // g.addEdge(6,5,1,0);

//     // int n = g.adjList.size();
//     // vector<int> parent(n);
//     // int src = 0;
//     // int dest = 5;
    
//     // g.ShortestPath(src,dest,parent);
//     // stack<int> s;
//     // s.push(dest);
//     // while(s.top()!=src)
//     // {
//     //     s.push(parent[dest]);
//     //     dest = s.top();
//     // }

//     // while(!s.empty())
//     // {
//     //     cout<<s.top()<<" ";
//     //     s.pop();
//     // }


//     Graph g;
//     g.addEdge(0,1,5,1);
//     g.addEdge(0,2,3,1);
//     g.addEdge(2,1,2,1);
//     g.addEdge(1,3,3,1);
//     g.addEdge(2,3,5,1);
//     g.addEdge(2,4,6,1);
//     g.addEdge(3,3,1,1);
//     // g.addEdge(6,5,1,0);

//     int src =0;
//     int dest = 3;
//     stack<int> topoOrder;
//     unordered_map<int,bool> isvisited;
//     g.TopologicalSortDfs(src,isvisited,topoOrder);

//     g.ShortestPathDfs(dest,topoOrder);
// }
// ***********************************************************************************************************

// #include <iostream>
// #include <string>
// #include <unordered_map>

// using namespace std;

// char findFirstNonRepeatingChar(const string& str) {
//     string evenChars = "";
//     string oddChars = "";

//     // Separate even and odd indexed characters
//     for (int i = 0; i < str.length(); i++) {
//         if (i % 2 == 0) {
//             evenChars += str[i];
//         } else {
//             oddChars += str[i];
//         }
//     }

//     // Create a map to count the occurrences of characters in evenChars
//     unordered_map<char, int> charCount;
//     for (char c : evenChars) {
//         charCount[c]++;
//     }

//     // Find the first non-repeating character in evenChars
//     for (char c : evenChars) {
//         if (charCount[c] == 1) {
//             return c;
//         }
//     }

//     // If no non-repeating character is found in evenChars, check oddChars
//     for (char c : oddChars) {
//         if (charCount[c] == 1) {
//             return c;
//         }
//     }

//     // If no non-repeating character is found in either evenChars or oddChars, return -1
//     return '-1';
// }

// int main() {
//     string str;
//     cin >> str;

//     char result = findFirstNonRepeatingChar(str);

//     if(result == '-1')
//     {
//         return -1;
//     }

//     cout << result << endl;

//     return 0;
// }


// #include <iostream>
// #include <string>
// #include <unordered_map>

// using namespace std;

// char findFirstNonRepeatingChar(const string& str) {
//     string evenChars = "";
//     string oddChars = "";

//     // Separate even and odd indexed characters
//     for (int i = 0; i < str.length(); i++) {
//         if (i % 2 == 0) {
//             evenChars += str[i];
//         } else {
//             oddChars += str[i];
//         }
//     }

//     // Create a map to count the occurrences of characters in evenChars
//     unordered_map<char, int> charCount;
//     for (char c : evenChars) {
//         charCount[c]++;
//     }

//     // Find the first non-repeating character in evenChars
//     for (char c : evenChars) {
//         if (charCount[c] == 1) {
//             return c;
//         }
//     }

//     // If no non-repeating character is found in evenChars, check oddChars
//     for (char c : oddChars) {
//         if (charCount[c] == 1) {
//             return c;
//         }
//     }

//     // If no non-repeating character is found in either evenChars or oddChars, return '-1' as a character
//     return '-';
// }

// int main() {
//     string str;
//     cin >> str;

//     char result = findFirstNonRepeatingChar(str);

//     cout << result << endl;

//     return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

// DFS function to calculate count of subordinates
void getSubordinatesCount(vector<int> &boss, vector<int> &subCount, int emp) {

  if (subCount[emp-1] != -1)
    return;

  subCount[emp-1] = 0;

  for (int i = 0; i < boss.size(); i++) {
    if (boss[i] == emp) {
      getSubordinatesCount(boss, subCount, i+1);
      subCount[emp-1] += subCount[i] + 1;
    }
  }
}

int main() {

  int n;
  cin >> n;

  vector<int> boss(n);
  for(int i = 0; i < n; i++) {
    cin >> boss[i]; 
  }

  vector<int> subCount(n, -1);
  getSubordinatesCount(boss, subCount, 1);

  for (int i = 0; i < n; i++) {
    cout << subCount[i] << " ";
  }

  return 0;
}