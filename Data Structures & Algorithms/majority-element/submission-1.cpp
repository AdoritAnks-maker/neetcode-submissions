class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (auto x : nums) {
            mpp[x]++;
        }
        int mx_em = INT_MIN;
        for (auto& p : mpp) {
            mx_em = max(mx_em, p.second);
        }
        int elem = 0;
        for (auto& t : mpp) {
            if (mx_em == t.second)
                elem = t.first;
        }
        return elem;
    }
};