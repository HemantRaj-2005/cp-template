#include <bits/stdc++.h>
using namespace std;
// Theory - Topological sort is a linear ordering of vertices such that for every directed edge u -> v, u appears before v in the ordering.
// Requirement - the graph should be a DAG
// topo sort through DFS
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){
    visited[node] = 1;
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(int V, vector<vector<int>> &adj){
    vector<bool> visited(V,0);
    stack<int> st;
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }
    vector<int> topoAns;
    while(!st.empty()){
        topoAns.push_back(st.top());
        st.pop();
    }
    return topoAns;
}

// Topo sort through BFS or Kahn's algorithm
vector<int> topoSortBFS(int V, vector<vector<int>> &adj){
    vector<int> in_degree(V,0);
    for(int i = 0; i < V; i++){
        for(auto it: adj[i]){
            in_degree[it]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(in_degree[i] == 0) q.push(i);
    }
    vector<int> topoAns;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoAns.push_back(node);
        for(auto it : adj[node]){
            in_degree[it]--;
            if(in_degree[it] == 0) q.push(it);
        }
    }
    return topoAns;
}

int main() {
    
    return 0;
}