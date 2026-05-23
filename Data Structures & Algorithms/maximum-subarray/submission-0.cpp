class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int mx_sum = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            mx_sum = max(sum, mx_sum);

            if (sum < 0) {
                sum = 0;
            }
        }
        return mx_sum ;
    }
};
