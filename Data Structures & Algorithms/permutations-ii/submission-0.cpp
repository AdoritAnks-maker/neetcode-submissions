class Solution {
   public:
    void solve(vector<int>& nums, vector<int>& op, set<vector<int>>& st) {
        if (nums.size() == 0) {
            st.insert(op);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            vector<int> ip = nums;
            vector<int> op1 = op;
            op1.push_back(nums[i]);
            ip.erase(ip.begin() + i);
            solve(ip, op1, st);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>op;
        set<vector<int>>st;
        solve(nums, op,st);
        vector<vector<int>>ans(st.begin() , st.end());
        return ans;
    }
};