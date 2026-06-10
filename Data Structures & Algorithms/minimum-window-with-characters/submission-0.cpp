class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        for (char c : t) {
            need[c]++;
        }
        int required = t.size();
        int left = 0;
        int right = 0;
        int start = 0;
        int min_len = INT_MAX;
        int n = s.size();
        while (right < n) {
            if (need[s[right]] > 0) {
                required--;
            }
            need[s[right]]--;
            while (required == 0) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start = left;
                }
                need[s[left]]++;
                if (need[s[left]] > 0) {
                    required++;
                }
                left++;
            }
            right++;
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};