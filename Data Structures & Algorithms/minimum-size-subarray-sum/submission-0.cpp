class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int mn_lentt = INT_MAX;

        while(j < nums.size()) {
            sum += nums[j];

            while(sum >= target) {
                mn_lentt = min(mn_lentt, j - i + 1);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return mn_lentt == INT_MAX ? 0 : mn_lentt;
    }
};