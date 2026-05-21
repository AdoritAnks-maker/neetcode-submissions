class Solution {
   public:
    long long totalspeed(vector<int>& piles, int speed) {
        long long totalhours = 0;
        for (auto x : piles) {
            totalhours += (x + speed - 1) / speed;
        }
        return totalhours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long start = 1;
        long long end = *max_element(piles.begin(), piles.end());
        long long ans = *max_element(piles.begin(), piles.end());
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long time = totalspeed(piles, mid);
            if (time <= h) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
