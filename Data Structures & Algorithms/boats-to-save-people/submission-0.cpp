
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        vector<int> nums = people;

        int i = 0;
        int j = n - 1;
        int cnt = 0;

        sort(nums.begin(), nums.end());

        while(i <= j) {
            int sum = nums[i] + nums[j];

            if(sum <= limit) {
                i++;
            }

            j--;
            cnt++;
        }

        return cnt;
    }
};