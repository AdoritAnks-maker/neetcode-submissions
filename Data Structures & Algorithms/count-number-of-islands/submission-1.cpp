class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;
    vector<vector<char>> g;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    void bfs(int x, int y) {
        visited[x][y] = true;
        queue<pair<int, int>> q;
        q.push({x, y});

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    !visited[nr][nc] &&
                    g[nr][nc] == '1') {

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        g = grid;
        n = g.size();
        m = g[0].size();

        visited.assign(n, vector<bool>(m, false));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && g[i][j] == '1') {
                    count++;
                    bfs(i, j);
                }
            }
        }

        return count;
    }
};