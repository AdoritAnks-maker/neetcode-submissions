class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (auto x : nums) {
            if (mpp.find(x) != mpp.end()) {
                return x;
            }
            mpp[x]++;
        }
        return -1;
    }
};
