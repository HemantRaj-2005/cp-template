#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

/**
Theory and Algorithm 
1. Randomly choose any vertex. The vertex connecting to the is usually selected
2. Find all the edges that connects the tree to new vertices
3. Find the least weight edge among those
*/

int prismMST(int V, vector<vector<int>> &adj){
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<bool> visited(V, false);
    int cost = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        cost += d;
        for(auto it : adj[u]){
            int v = it[0];
            int w = it[1];
            if(!visited[v]) pq.push({w, v});
        }
    }
    return cost;
}
