class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mpp;
        for (auto x : s1) {
            mpp[x]++;
        }
        int k = s1.size();
        int count = mpp.size();
        int i = 0;
        int j = 0;
        while (j < s2.size()) {
            if (mpp.find(s2[j]) != mpp.end()) {
                mpp[s2[j]]--;
                if (mpp[s2[j]] == 0) {
                    count--;
                }
            }
            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {
                if (count == 0) {
                    return true;
                }
                if (mpp.find(s2[i]) != mpp.end()) {
                    if (mpp[s2[i]] == 0) {
                        count++;
                    }
                    mpp[s2[i]]++;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};
