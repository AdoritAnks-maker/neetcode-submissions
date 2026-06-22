class Solution {
public:
    void solve(vector<int>&op ,vector<int>&nums,vector<vector<int>>&ans ){
        if(nums.size()==0){
            ans.push_back(op);
            return ;
        }
        for(int i  =0; i<nums.size();i++){
            vector<int>ip =  nums;
            vector<int>op1 = op ;
            op1.push_back(nums[i]);
            ip.erase(ip.begin()+i);
            solve(op1, ip,ans);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>op ;
        vector<vector<int>>ans;
        solve(op , nums , ans);
        return ans;
    }
};
