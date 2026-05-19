class Solution {
public:
    int search(vector<int>& nums, int target) {
        bool ok = false ;
        int ans = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
             ok=true ;
             ans = i;
             
            }
        }
        if(ok)return ans ;
        return -1;
      
    }
};
