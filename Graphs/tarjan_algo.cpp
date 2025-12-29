// What is tarjan's algorithm?
// Tarjan's algorithm is a linear time algorithm to find all strongly connected components of a graph.
// It is better than kosaraju's algorithm, because it can find all SCC in one dfs.
// Time complexity: O(V + E)
// Space complexity: O(V + E)

void dfs(int node, vector<vector<int>> &adj, stack<int>&st, vector<bool>&visited, vector<int>&tin, vector<int>&lowlink, vector<bool>&inStack, int &timer, int &count){
    visited[node] = 1;
    tin[node] = lowlink[node] = timer++;
    inStack[node] = 1;
    st.push(node);
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it, adj, st, visited, tin, lowlink, inStack, timer, count);
            lowlink[node] = min(lowlink[node], lowlink[it]);
        }
        else if(inStack[it]){
            lowlink[node] = min(lowlink[node], tin[it]);
        }
    }
    if(tin[node] == lowlink[node]){
        while(st.top() != node){
            inStack[st.top()] = 0;
            st.pop();
        }
        inStack[node] = 0;
        st.pop();
        count++;
    }
}

int tarjan(int n, vector<vector<int>> &adj){
    vector<bool> visited(n, 0);
    stack<int> st;
    vector<int> tin(n,-1);
    vector<int> lowlink(n,-1);
    vector<bool> inStack(n, 0);
    int timer = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, adj, st, visited, tin, lowlink, inStack, timer, count);
        }
    }

    return count;
}