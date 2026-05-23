class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {

                if (nums[i - 1] <= j) {
                    dp[i][j] =
                        dp[i - 1][j - nums[i - 1]] +
                        dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][k];
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;

        for (int x : nums) {
            sum += x;
        }

        if (abs(target) > sum) {
            return 0;
        }

        if ((sum + target) % 2) {
            return 0;
        }

        int tt = (sum + target) / 2;

        return solve(nums, tt);
    }
};