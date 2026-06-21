class Solution {
public:
    void solve(int start, int sum, vector<int>& candidate, vector<int>& op,
               vector<vector<int>>& res, int target) {
        if (sum == target) {
            res.push_back(op);
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = start; i < candidate.size(); i++) {
            op.push_back(candidate[i]);
            solve(i, sum + candidate[i], candidate, op, res, target);
            op.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int sum = 0;
        vector<int> op;
        solve(0, sum, nums, op, res, target);
        return res;
    }
};