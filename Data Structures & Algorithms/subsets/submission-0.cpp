class Solution {
   public:
    void solve(vector<int> nums, vector<int>& op, set<vector<int>>& st) {
        if (nums.size() == 0) {
            st.insert(op);
            return;
        }
        vector<int> op1 = op;
        vector<int> op2 = op;
        op2.push_back(nums[0]);
        nums.erase(nums.begin());
        solve(nums, op1, st);
        solve(nums, op2, st);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> op;
        solve(nums, op, st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
