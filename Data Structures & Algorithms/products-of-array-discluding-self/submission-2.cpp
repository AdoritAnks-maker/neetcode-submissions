class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefprod(n);
        vector<int> suffprod(n);
        vector<int> ans(n);
        prefprod[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefprod[i] = prefprod[i - 1] * nums[i];
        }

        suffprod[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffprod[i] = suffprod[i + 1] * nums[i];
        }
        for (int i = 0; i < n; i++) {

            if (i == 0) {
                ans[i] = suffprod[i + 1];
            }
            else if (i == n - 1) {
                ans[i] = prefprod[i - 1];
            }
            else {
                ans[i] = prefprod[i - 1] * suffprod[i + 1];
            }
        }

        return ans;
    }
};