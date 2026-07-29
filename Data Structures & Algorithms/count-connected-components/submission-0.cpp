class Solution {
public:
    vector<int> vis;
    vector<vector<int>> graph;

    void dfs(int node) {
        vis[node] = 1;

        for (auto neigh : graph[node]) {
            if (!vis[neigh]) {
                dfs(neigh);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        vis.resize(n, 0);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
                components++;
            }
        }

        return components;
    }
};