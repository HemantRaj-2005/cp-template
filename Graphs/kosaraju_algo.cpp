#include "bits/stdc++.h"
using namespace std;

// here we will do dfs
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){
    visited[node] = 1;
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it, adj, visited,st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>> &adj, vector<bool> &visited){
    visited[node] = 1;
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs2(it, adj, visited);
        }
    }
}

int kosaraju(int n, vector<vector<int>> &adj){
    stack<int> st;
    vector<bool> visited(n,0);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, adj, visited,st);
        }
    }

    vector<vector<int>> transpose(n);
    for(int i = 0; i < n; i++){
        for(auto it : adj[i]){
            transpose[it].pb(i);
        }
    }

    visited = vector<bool>(n,0);
    int cnt = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]){
            dfs2(node, transpose, visited);
            cnt++;
        }
    }

    return cnt;
}