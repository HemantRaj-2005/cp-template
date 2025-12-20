#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion
{
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

public:
    DisjointSetUnion(int n)
    {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        rank.assign(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    bool find(int u, int v) { return findParent(u) == findParent(v); }

    void unionByRank(int u, int v)
    {
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if (parent_u == parent_v)
        {
            return;
        }
        if (rank[parent_u] < rank[parent_v])
        {
            parent[parent_u] = parent_v;
        }
        else if (rank[parent_v] < rank[parent_u])
        {
            parent[parent_v] = parent_u;
        }
        else
        {
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if (parent_u == parent_v)
        {
            return;
        }
        if (size[parent_u] < size[parent_v])
        {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else
        {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};