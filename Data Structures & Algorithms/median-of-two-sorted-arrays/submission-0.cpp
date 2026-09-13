class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>temp ; 
        for(int i  = 0;i<n ;i++){
            temp.push_back(nums1[i]);
        }
        for(int i = 0 ;i<m ;i++){
            temp.push_back(nums2[i]);
        }
        sort(temp.begin() , temp.end());
        int sz = temp.size();
        if(sz%2==1){
            return (double)temp[sz/2];
        }else{
            return (double)(temp[(sz-1)/2]+temp[(sz+1)/2])/2 ;
        }
    }
};