class Solution {
public:
    vector<vector<int>> graph;
    vector<int> state;
    vector<int> order;
    bool dfs(int node) {
        state[node] = 1;
        for (auto neigh : graph[node]) {
            if (state[neigh] == 0) {
                if (dfs(neigh)) {
                    return true;
                }
            } else if (state[neigh] == 1) {
                return true;
            }
        }
        state[node] = 2;
        order.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        graph.resize(n + 1);
        state.assign(n + 1, 0);
        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            graph[prereq].push_back(course);
        }
        for (int i = 0; i < n; i++) {
            if (state[i] == 0) {
                if (dfs(i)) {
                    return {};
                }
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};