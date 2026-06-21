class Solution {
public:
    void solve(int start, int sum, vector<int>& candidates, vector<int>& op,
               vector<vector<int>>& res, int target) {
        if (sum == target) {
            res.push_back(op);
            return;
        }
        if (sum > target) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            op.push_back(candidates[i]);
            solve(i + 1, sum + candidates[i], candidates, op, res, target);
            op.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        int sum = 0;
        vector<int> op;
        vector<vector<int>> res;

        solve(0, sum, candidates, op, res, target);

        return res;
    }
};