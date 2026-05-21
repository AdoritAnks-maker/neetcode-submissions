class Solution {
   public:
    string encode(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        vector<int> sizes;
        for (auto s : strs) {
            sizes.push_back(s.size());
        }
        string res = "";
        for (auto x : sizes) {
            res += to_string(x) + ",";
        }
        res += "#";
        for (string k : strs) {
            res += k;
        }
        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) {
            return {};
        }
        vector<string> ans;
        vector<int> sizes;
        int i = 0;
        while (s[i] != '#') {
            string curr = "";
            while (s[i] != ',') {
                curr += s[i];
                i++;
            }
            sizes.push_back(stoi(curr));
            i++;
        }
        i++;
        for (int sz : sizes) {
            ans.push_back(s.substr(i, sz));
            i += sz;
        }
        return ans;
    }
};
