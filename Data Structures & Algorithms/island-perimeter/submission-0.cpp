class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;
    vector<vector<int>> g;

    int ans = 0;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(int x, int y) {
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == 0) {
                ans++;
            }
            else if (!visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        g = grid;

        n = grid.size();
        m = grid[0].size();
        ans = 0;
        visited.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};