class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;

        int sum = digits[n - 1] + 1;
        int carry = sum / 10;
        ans.push_back(sum % 10);

        int j = n - 2;

        while (j >= 0) {
            int summ = digits[j] + carry;
            ans.push_back(summ % 10);
            carry = summ / 10;
            j--;
        }

        if (carry) {
            ans.push_back(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};