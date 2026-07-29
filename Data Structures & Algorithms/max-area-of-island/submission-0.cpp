class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;
    vector<vector<int>> g;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int dfs(int x, int y) {
        visited[x][y] = true;
        int area = 1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                !visited[nx][ny] &&
                g[nx][ny] == 1) {

                area += dfs(nx, ny);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        g = grid;
        n = g.size();
        m = g[0].size();

        visited.assign(n, vector<bool>(m, false));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && g[i][j] == 1) {
                    ans = max(ans, dfs(i, j));
                }
            }
        }

        return ans;
    }
};