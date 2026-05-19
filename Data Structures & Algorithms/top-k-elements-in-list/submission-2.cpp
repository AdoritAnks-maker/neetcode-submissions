class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        vector<pair<int, int>> v(count.begin(), count.end());
        sort(v.begin(), v.end(), [](const pair<int, int> & a, const pair<int, int> & b) {
            return a.second > b.second;
        });
        vector<int>res;
        for(int i = 0; i < k; i++){
            res.push_back(v[i].first);
        }
        return res;
    }
};