class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0 ;
        int ans = 0  ;
        int mx_freq = INT_MIN;
        unordered_map<char, int>mpp;
        for(int right  =0 ; right < s.size() ; right++){
            mpp[s[right]]++;

            mx_freq =max(mx_freq, mpp[s[right]]);

            int replace_needed = right-left+1-mx_freq;
            while(replace_needed > k ){
                mpp[s[left]]--;
                left++;
                replace_needed =  right-left+1 - mx_freq;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
