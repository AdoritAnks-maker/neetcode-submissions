class Solution {
   public:
    vector<int> ans;

    void precompute(int n) {
        for (int i = 1; i * i <= n; i++) {
            ans.push_back(i * i);
        }
    }

    int numSquares(int n) {
        precompute(100000);
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int num : ans) {
                if (num > i) break;
                
                dp[i] = min(dp[i], 1 + dp[i - num]);
            }
        }
        return dp[n];
    }
};