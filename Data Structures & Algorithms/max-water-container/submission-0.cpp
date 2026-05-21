class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int right = n - 1;
        int mx_area = INT_MIN;
        while (left < right) {
            int ht = min(heights[left], heights[right]);
            int width = right - left;
            mx_area = max(mx_area, width * ht);
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return mx_area;
    }
};
