class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char , int>freq1;
        map<char , int>freq2;
        for(char c : s){
            freq1[c]++;
        }
        for(char x : t){
            freq2[x]++;
        }
        if(freq1==freq2)return true;
        return false;
    }
};