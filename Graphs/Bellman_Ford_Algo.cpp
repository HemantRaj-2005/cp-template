#include <bits/stdc++.h>
using namespace std;

/**
Theory and Algorithm
Bellman Ford is used to find the shortest path in a graph with negative weights.
Time Complexity - O(V*E)
Space Complexity - O(V)
1. Set the starting node distance to 0 and all other nodes to INT_MAX
2. For V-1 times, relax all the edges (relaxation means updating the distance if a shorter path is found)
3. Try relaxating N-1 times
4. Try one more time, if the distance is updated then there is a negative cycle
    4.1 If the distance is updated then return -1
    4.2 If the distance is not updated then return the distance array
*/

// here the function of Bellman Ford algo
vector<int> bellmanFord(int V, vector<vector<int>> &adj, int src){
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    for(int i = 0; i < V; i++){
        for(auto it : adj){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    for(auto it : adj){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
            return {-1};
        }
    }
    
    return dist;
}