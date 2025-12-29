#include <bits/stdc++.h>
using namespace std;

/**
Theory and Algorithm
Kruskal is used to find the minimum spanning tree of a graph.
Time Complexity - O(ElogE)
Space Complexity - O(E)

Algorithm:
1. Sort all the edges in a non-decreasing order of their weight. 
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If the cycle is not formed, include this edge. Else, discard it.  It uses the Disjoint Sets to detect cycles.
3. Repeat step 2 until there are (V-1) edges in the spanning tree.
*/
class DisjointSetUnion{
public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;
    DisjointSetUnion(int n){
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        rank.assign(n + 1, 0);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    bool find(int u, int v) { return findParent(u) == findParent(v); }

    void unionByRank(int u, int v){
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if (parent_u == parent_v){
            return;
        }
        if (rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        }
        else if (rank[parent_v] < rank[parent_u]){
            parent[parent_v] = parent_u;
        }
        else{
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }

    void unionBySize(int u, int v){
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if (parent_u == parent_v){
            return;
        }
        if (size[parent_u] < size[parent_v]){
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else{
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};

bool compare(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int kruskal(int V, vector<vector<int>> &edges){
    sort(edges.begin(), edges.end(), compare);
    DisjointSetUnion ds(V);
    int cost = 0, count = 0;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        int parent_u = ds.findParent(u);
        int parent_v = ds.findParent(v);
        if(parent_u != parent_v){
            ds.unionByRank(parent_u, parent_v);
            cost += w;
            count++;
            if(count == V-1) break;
        }
    }
    return cost;
}