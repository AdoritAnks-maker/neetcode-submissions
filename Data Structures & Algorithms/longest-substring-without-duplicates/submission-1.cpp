class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int mx_lentt = 0;
        map<char, int> mpp;
        while (j < s.size()) {
            mpp[s[j]]++;

            while (mpp[s[j]] > 1) {
                mpp[s[i]]--;

                if (mpp[s[i]] == 0) {
                    mpp.erase(s[i]);
                }
                i++;
            }
            mx_lentt = max(mx_lentt, j - i + 1);
            j++;
        }
        return mx_lentt;
    }
};
