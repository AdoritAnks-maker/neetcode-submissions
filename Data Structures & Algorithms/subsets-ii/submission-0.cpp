class Solution {
public:
    void solve(vector<int>arr , vector<int>op , set<vector<int>>&st){
        if(arr.size()==0){
            st.insert(op);
            return ;
        }
        vector<int>op1=op;
        vector<int>op2 =op;
        op2.push_back(arr[0]);
        arr.erase(arr.begin());
        solve(arr, op1 , st); // exclude the element 
        solve(arr, op2 ,st); // include the element 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        set<vector<int>>st;
        vector<int>op;
        solve(nums , op , st);
        vector<vector<int>>res(st.begin() , st.end());
        return res;
    }
};