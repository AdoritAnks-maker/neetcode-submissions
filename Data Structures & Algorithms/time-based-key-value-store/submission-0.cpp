class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> mpp;
    TimeMap() {}

    void set(string key, string value, int timestamp) { mpp[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
        if (mpp.find(key) == mpp.end()) {
            return "";
        }
        auto&v=  mpp[key];
        int left = 0;
        int right = v.size() - 1;
        string ans = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid].first <= timestamp) {
                ans = v[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
