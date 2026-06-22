class Solution {
   public:
    void solve(int start, int n, int k, vector<vector<int>>& ans, vector<int>& op) {
        if (op.size() == k) {
            ans.push_back(op);
            return;
        }
        for (int i = start; i <= n; i++) {
            op.push_back(i);
            solve(i + 1, n, k, ans, op);
            op.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>op;
        solve(1, n, k, ans, op);
        return ans;
    }
};