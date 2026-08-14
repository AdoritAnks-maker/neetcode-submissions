class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        unordered_map<int, int> mpp;
        while (j < n) {
            mpp[nums[j]]++;
            while (abs(j - i) > k) {
                mpp[nums[i]]--;
                i++;
            }
            if(mpp[nums[j]]>1){
                return true; 
            }
            j++;
        }
        return false;
    }
};