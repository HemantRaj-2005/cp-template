#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

/**
Theory and Algorithm
Dijkrista is used to find the shortest path in a graph with non-negative weights.
Time Complexity - O((V+E)logV)
Space Complexity - O(V+E)

Algorithm:
1. Initialize distance array with INT_MAX
2. Distance of source = 0
3. Process nodes in topological order
    4.1 For each vertext u:
            For every edge u->v, with weight w
            if(dist[u] + w < dist[v])
                dist[v] = dist[u] + w
5. Return distance array
*/

// here the function of Dijkrista algo
vector<int> dijkrista(int V, vector<vector<int>> &adj, int src){
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for(auto it : adj[u]){
            int v = it[0];
            int w = it[1];
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}