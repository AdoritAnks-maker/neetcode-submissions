
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        while (!q.empty() && fresh > 0) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= n ||
                        ny < 0 || ny >= m)
                        continue;

                    if (!vis[nx][ny] && grid[nx][ny] == 1) {
                        vis[nx][ny] = true;
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }

            minutes++;
        }
        return fresh > 0 ? -1 : minutes; 
    }
};