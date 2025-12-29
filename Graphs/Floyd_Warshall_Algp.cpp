#include<bits/stdc++.h>
using namespace std;

/**
Theory and Algorithm
Floyd Warshall is dp based algorithm used to find the shortest path in a graph with negative weights.
Time Complexity - O(V^3)
Space Complexity - O(V^2)
When to use ? - When the graph has negative weights and we want to find the shortest path between all pairs of vertices.

Algorithm:
1. Initialize the 2d distance array with INT_MAX
2. 3 nested loop is the heart of the algorithm
    for(k = 1 to n)
        for( i = 1 to n)
            for(j = 1 to n)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

3. How to detect negative cycle? 
    3.1 if dist[i][i] < 0 then there is a negative cycle
*/

vector<vector<int>> floydWarshall(int V, vector<vector<int>> &adj){
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
    for(int i = 0; i < V; i++){
        dist[i][i] = 0;
    }
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for(int i = 0; i < V; i++){
        if(dist[i][i] < 0){
            return {-1};
        }
    }
    return dist;
}