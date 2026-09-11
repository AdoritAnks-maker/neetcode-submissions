class Solution {
public:
    bool countdays(vector<int>& nums, int capacity, int days) {
        int sum = 0;
        int count = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(sum + nums[i] <= capacity) {
                sum += nums[i];
            }
            else {
                count++;
                sum = nums[i];
            }
        }

        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        int ans = end;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(countdays(weights, mid, days)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};