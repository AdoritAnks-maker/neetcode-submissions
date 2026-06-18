class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int  , int>presum_map;
        int sum = 0;
        int count = 0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            }
            if(presum_map.find(sum-k)!=presum_map.end()){
                count+=presum_map[sum-k];
            }
            presum_map[sum]++;
        }
        return count;
    }
};