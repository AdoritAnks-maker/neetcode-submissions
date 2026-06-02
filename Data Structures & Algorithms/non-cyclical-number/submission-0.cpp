class Solution {
   public:
    bool isHappy(int n) {
        unordered_map<int, int> mpp;
        while (n != 1 && mpp.find(n) == mpp.end()) {
            mpp[n]++;
            int sum = 0;
            while (n) {
                int d = n % 10;
                sum += (d * d);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
