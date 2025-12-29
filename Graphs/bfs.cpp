#include<bits/stdc++.h>
using namespace std;

void bfs(int node, vector<vector<int>> &adj, vector<int> &visited){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto it : adj[front]){
            if(!visited[it]){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
}