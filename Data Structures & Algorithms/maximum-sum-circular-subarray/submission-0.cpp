class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int maxsum = nums[0];
        int minsum = nums[0];
        int currmax = 0;
        int currmin = 0;
        for (auto x : nums) {
            currmax = max(x, currmax + x);
            maxsum = max(maxsum, currmax);

            currmin = min(x, currmin + x);
            minsum = min(minsum, currmin);

            total += x;
        }
        if (maxsum < 0) return maxsum;
        return max(maxsum, total - minsum);
    }
};