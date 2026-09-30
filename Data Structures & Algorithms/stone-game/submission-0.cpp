class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; i++, j++) {
                if (g == 0) {
                    dp[i][j] = piles[i];
                }
                if (g == 1) {
                    dp[i][j] = max(piles[i], piles[j]);
                } else {
                    int val1 = (i + 2 <= j) ? dp[i + 2][j] : 0;
                    int val2 = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
                    int val3 = (i <= j - 2) ? dp[i][j - 2] : 0;

                    int ans1 = piles[i] + min(val1, val2);
                    int ans2 = piles[j] + min(val2, val3);
                    dp[i][j] = max(ans1, ans2);
                }
            }
        }
        int total = accumulate(piles.begin(), piles.end(),0);

        return dp[0][n - 1] > total - dp[0][n - 1];
    }
};