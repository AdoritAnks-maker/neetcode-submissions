class Solution {
public:
    bool isPalindrome(string s) {
        string result="";
        for(char c : s){
            if(isalnum(c)){
                result+=tolower(c);
            }
        }
        return result==string(result.rbegin(),result.rend());
    }
   
};
