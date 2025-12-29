#include <bits/stdc++.h>
using namespace std;

/**
Algorithm:
1. Do topological sort
2. Initialize distance array with INT_MAX
3. Distance of source = 0
4. Process nodes in topological order
    4.1 For each vertext u:
            For every edge u->v, with weight w
            if(dist[u] + w < dist[v])
                dist[v] = dist[u] + w
5. Return distance array
6. If we want the longest path then multiply the weight with -1 and do the same process
*/

// here the function of topo sort

vector<int> shortestPathDAG(int V, vector<vector<int>> &adj, int src){
    vector<int> topo = topologicalSort(V, adj);
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    for(int i = 0; i < topo.size(); i++){
        int u = topo[i];
        for(auto it : adj[u]){
            int v = it[0];
            int w = it[1];
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}
