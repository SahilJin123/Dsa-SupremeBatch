int Dijkistra(int src,int dest)
    // {
    //     int n = adjList.size();
    //     vector<int> distance(n+1,INT_MAX);
    //     set<pair<int,int>> s;

    //     queue<int> q;
    //     q.push(src);
    //     distance[src] = 0;

    //     while(!q.empty())
    //     {
    //         int fnode = q.front();
    //         q.pop();

    //         for(auto nbr : adjList[fnode])
    //         {
    //             distance[nbr.first] = min(distance[fnode] + nbr.second,distance[nbr.first]);
    //             q.push(nbr.first);
    //             s.insert({distance[nbr.first],nbr.first});
    //         }
    //     }

    // }