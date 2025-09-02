
// Graph constructoin

vector<vector<int>> constructGraph(int n, int m, bool directed = false){

    vector<vector<int>> graph(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);

        if(!directed) graph[v].push_back(u);
    }

    return graph;
}

// DFS traversal for graph

void dfs(int node, vector<int>& vis, vector<vector<int>>& graph){
    for(int v: graph[node]){
        if(vis[v] == 0){
            vis[v] = 1;
            dfs(v, vis, graph);
        }
    }
}
